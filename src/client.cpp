#include <grpcpp/grpcpp.h>
#include "file_transfer.grpc.pb.h"
#include <fstream>
#include <filesystem>
#include <iostream>
#include <iomanip>
#include <chrono>

namespace fs = std::filesystem;
using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using grpc::ClientReader;
using grpc::ClientWriter;
using filetransfer::FileTransfer;
using filetransfer::FileChunk;
using filetransfer::FileRequest;
using filetransfer::TransferStatus;
using FileList = std::vector<std::pair<std::string, std::string>>;

class ProgressBar {
public:
    ProgressBar(size_t total, const std::string& filename, size_t width = 50)
        : total_(total), width_(width), progress_(0), filename_(filename) {
        start_time_ = std::chrono::high_resolution_clock::now();
    }

    void update(size_t value) const {
        progress_ = value;
        display();
    }

    void display() const {
        float ratio = total_ == 0 ? 1 : static_cast<float>(progress_) / total_;
        size_t bar_width = total_ == 0 ? width_ : static_cast<size_t>(ratio * width_);
        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = now - start_time_;
        double speed = progress_ / elapsed.count();
        std::string speed_str = formatSize(speed);

        std::cout << "\r" << std::setw(35) << std::left << filename_.substr(0, 35) << " ";
        std::cout << std::setw(15) << std::right << formatSize(total_) << " [";
        for (size_t i = 0; i < bar_width; ++i) std::cout << "=";
        for (size_t i = bar_width; i < width_; ++i) std::cout << " ";
        std::cout << "] " << std::setw(3) << std::right << static_cast<int>(ratio * 100) << "% ";
        std::cout << std::setw(20) << std::right << speed_str + "/s";
        std::cout.flush();
    }

    void finish() const {
        update(total_);
        std::cout << std::endl;
    }

private:
    size_t total_;
    size_t width_;
    mutable size_t progress_;
    std::string filename_;
    std::chrono::high_resolution_clock::time_point start_time_;

    std::string formatSize(double size) const {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2);
        if (size < 1024) {
            oss << size << " B";
        } else if (size < 1024 * 1024) {
            oss << size / 1024 << " KB";
        } else if (size < 1024 * 1024 * 1024) {
            oss << size / (1024 * 1024) << " MB";
        } else {
            oss << size / (1024 * 1024 * 1024) << " GB";
        }
        return oss.str();
    }
};

class FileTransferClient {
public:
    FileTransferClient(std::shared_ptr<Channel> channel)
        : stub_(FileTransfer::NewStub(channel)) {}
    bool Upload(const std::string& local_path, const std::string& remote_path) {
        // Remove trailing slash if present
        std::string local_path_copy = RemoveTrailingSlash(local_path);
        std::string remote_path_copy = RemoveTrailingSlash(remote_path);
        if (!fs::exists(local_path_copy))
        {
            std::cerr << "No such file or directory: " << local_path_copy << std::endl;
            return false;
        }
        
        // Generate file list
        FileList file_list;
        GenerateFileList(local_path_copy, remote_path_copy, file_list);

        // Send file list
        grpc::ClientContext context;
        TransferStatus status;
        std::unique_ptr<grpc::ClientWriter<FileChunk>> writer(stub_->Upload(&context, &status));

        SendFileList(writer.get(), file_list);

        writer->WritesDone();
        grpc::Status grpc_status = writer->Finish();
        if (grpc_status.ok() && status.success()) {
            std::cout << "Upload successful" << std::endl;
            return true;
        } else {
            std::cerr << "Upload failed: " << status.message() << std::endl;
            return false;
        }
    }

    bool Download(const std::string& remote_path, const std::string& local_path) {
        ClientContext context;
        FileRequest request;
        std::string remote_path_copy = RemoveTrailingSlash(remote_path);
        request.set_path(remote_path_copy);
        fs::create_directories(local_path);
        std::unique_ptr<ClientReader<FileChunk>> reader(stub_->Download(&context, request));

        FileChunk chunk;
        std::string filepath;
        std::ofstream outfile;
        size_t current_size = 0;
        ProgressBar *progress_bar = nullptr;
        while (reader->Read(&chunk)) {
            if (chunk.filename().empty() && chunk.content().empty() && chunk.is_dir() == false && chunk.filesize() == 0) break;
            if (chunk.is_dir()) {
                fs::create_directories(local_path + "/" + chunk.filename());
                continue;
            }
            if (!outfile.is_open() || filepath != chunk.filename())
            {
                filepath = chunk.filename();
                current_size = 0;
                outfile.close();
                if (progress_bar) {
                    progress_bar->finish();
                }
                progress_bar = new ProgressBar(chunk.filesize(), fs::path(filepath).filename());
                outfile.open(local_path + "/" + filepath, std::ios::out | std::ios::binary);
                if (!outfile) {
                    std::cerr << "Failed to open file for writing: " << local_path + "/" + filepath << std::endl;
                    continue;
                }
            } 
            outfile.write(chunk.content().data(), chunk.content().size());
            current_size += chunk.content().size();
            progress_bar->update(current_size);
        }
        if (progress_bar && outfile)
        {
            progress_bar->finish();
            outfile.close();
        }
        Status grpc_status = reader->Finish();
        if (grpc_status.ok()) {
            std::cout << "Download successful." << std::endl;
            return true;
        } else {
            std::cerr << "Download failed. Error message: " << grpc_status.error_message() << std::endl;
            return false;
        }
    }

private:
    std::unique_ptr<FileTransfer::Stub> stub_;
    std::string RemoveTrailingSlash(const std::string& path) {
        if (!path.empty() && path.back() == '/') {
            return path.substr(0, path.size() - 1);
        }
        return path;
    }

    void GenerateFileList(const std::string& base_path, const std::string& remote_base_path, FileList& file_list) {
        fs::path base_path_fs = base_path;
        std::string parent_path = base_path_fs.parent_path();
        if (fs::is_directory(base_path))
        {
            file_list.push_back(std::make_pair(base_path, remote_base_path + "/" + base_path_fs.filename().string()));
            for (const auto& entry : fs::recursive_directory_iterator(base_path_fs)) {
                std::string relative_path = fs::relative(entry.path(), parent_path).string();
                std::string remote_path = remote_base_path + "/" + relative_path;
                file_list.push_back(std::make_pair(entry.path().string(), remote_path));
            }
        }else
        {
            file_list.push_back(std::make_pair(base_path, remote_base_path + "/" + base_path_fs.filename().string()));
        }    
    }

    void SendFileList(grpc::ClientWriter<FileChunk>* writer, const FileList& file_list) {
        for (const auto& file_pair : file_list) {
            fs::path local_path = file_pair.first;
            std::string remote_path = file_pair.second;
            
            if (fs::is_directory(local_path)) {
                FileChunk chunk;
                chunk.set_filename(remote_path);
                chunk.set_is_dir(true);
                writer->Write(chunk);
            } else if (fs::is_regular_file(local_path)) {
                size_t total_size = fs::file_size(file_pair.first);
                ProgressBar progress_bar(total_size, local_path.filename());

                std::ifstream infile(local_path, std::ios::in | std::ios::binary);
                if (!infile.is_open()) {
                    std::cerr << "Failed to open file for reading: " << local_path << std::endl;
                    continue;
                }

                FileChunk chunk;
                chunk.set_filename(remote_path);
                chunk.set_is_dir(false);

                constexpr size_t chunk_size = 4096; // Adjust as needed
                std::vector<char> buffer(chunk_size);
                size_t current_size = 0;
                while (!infile.eof()) {
                    infile.read(buffer.data(), chunk_size);
                    const size_t bytesRead = infile.gcount();
                    chunk.mutable_content()->assign(buffer.data(), bytesRead);
                    writer->Write(chunk);
                    current_size += bytesRead;
                    progress_bar.update(current_size);
                }
                infile.close();
                progress_bar.finish();
            }else {
                std::cerr << "Invalid file type: " << local_path << std::endl;
            }
        }
    }

};

void parse_address(const std::string& input, std::string& server_address, std::string& path) {
    size_t first_colon = input.find(':');
    size_t second_colon = input.find(':', first_colon + 1);

    if (first_colon != std::string::npos) {
        if (second_colon != std::string::npos) {
            // IP:port:path
            server_address = input.substr(0, second_colon);
            path = input.substr(second_colon + 1);
        } else {
            // IP:path, use default port 50051
            server_address = input.substr(0, first_colon) + ":50051";
            path = input.substr(first_colon + 1);
        }
    } else {
        std::cerr << "Invalid address format: " << input << std::endl;
        exit(1);
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage:\n"
                  << "  Download: ./client <server_address>:<remote_path> <local_path>\n"
                  << "  Upload: ./client <local_path> <server_address>:<remote_path>" << std::endl;
        return 1;
    }

    std::string arg1 = argv[1];
    std::string arg2 = argv[2];

    if (arg1.find(':') != std::string::npos && arg2.find(':') == std::string::npos) {
        // Download
        std::string server_address, remote_path;
        parse_address(arg1, server_address, remote_path);
        std::string local_path = arg2;

        FileTransferClient client(grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials()));
        client.Download(remote_path, local_path);

    } else if (arg1.find(':') == std::string::npos && arg2.find(':') != std::string::npos) {
        // Upload
        std::string local_path = arg1;
        std::string server_address, remote_path;
        parse_address(arg2, server_address, remote_path);

        FileTransferClient client(grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials()));
        client.Upload(local_path, remote_path);

    } else {
        std::cerr << "Invalid arguments format." << std::endl;
        return 1;
    }

    return 0;
}
