#include <grpcpp/grpcpp.h>
#include "file_transfer.grpc.pb.h"
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::ServerWriter;
using grpc::ServerReader;
using filetransfer::FileTransfer;
using filetransfer::FileChunk;
using filetransfer::FileRequest;
using filetransfer::TransferStatus;

class FileTransferServiceImpl final : public FileTransfer::Service {
public:
    Status Upload(ServerContext* context, ServerReader<FileChunk>* reader, TransferStatus* status) override {
        FileChunk chunk;
        std::ofstream outfile;
        std::string filepath;

        while (reader->Read(&chunk)) {
            if (chunk.is_dir()) {
                fs::create_directories(chunk.filename());
                continue;
            }

            if (!outfile.is_open() || filepath != chunk.filename()) {
                filepath = chunk.filename();
                outfile.close();
                outfile.open(filepath, std::ios::out | std::ios::binary);
                if (!outfile.is_open()) {
                    status->set_success(false);
                    status->set_message("Failed to open file for writing: " + filepath);
                    return Status::OK;
                }
            }
            outfile.write(chunk.content().data(), chunk.content().size());
        }
        outfile.close();
        status->set_success(true);
        status->set_message("upload successful");
        return Status::OK;
    }
    Status Download(ServerContext* context, const FileRequest* request, ServerWriter<FileChunk>* writer) override {
        fs::path path(request->path());
        std::string parent_path = path.parent_path();
        constexpr size_t chunk_size = 1024 * 1024; // Adjust as needed
        std::vector<char> buffer(chunk_size);
        try {
            if (fs::is_directory(path) && fs::exists(path)) {
                FileChunk chunk;
                chunk.set_filename(fs::relative(path, parent_path).string());
                chunk.set_is_dir(true);
                writer->Write(chunk);
                for (const auto& entry : fs::recursive_directory_iterator(path)) {
                    if (!fs::exists(entry.path())) continue;
                    FileChunk chunk;
                    chunk.set_filename(fs::relative(entry.path(), parent_path).string());
                    chunk.set_is_dir(entry.is_directory());
                    if (!entry.is_directory()) {
                        chunk.set_filesize(fs::file_size(entry.path()));
                        std::ifstream infile(entry.path(), std::ios::in | std::ios::binary);
                        while (!infile.eof()) {
                            infile.read(buffer.data(), chunk_size);
                            const size_t bytesRead = infile.gcount();
                            chunk.mutable_content()->assign(buffer.data(), bytesRead);
                            writer->Write(chunk);
                        }
                        infile.close();
                    }else
                    {
                        writer->Write(chunk);
                    }
                }
            } else if (fs::is_regular_file(path) && fs::exists(path)) {
                FileChunk chunk;
                chunk.set_filename(fs::relative(path, parent_path).string());
                chunk.set_is_dir(false);
                chunk.set_filesize(fs::file_size(path));
                std::ifstream infile(path, std::ios::in | std::ios::binary);
                while (!infile.eof()) {
                    infile.read(buffer.data(), chunk_size);
                    const size_t bytesRead = infile.gcount();
                    chunk.mutable_content()->assign(buffer.data(), bytesRead);
                    writer->Write(chunk);
                }
                infile.close();
            } else {
                FileChunk chunk;
                writer->Write(chunk);
                return grpc::Status(grpc::StatusCode::INTERNAL, "No such file or directory: [" + request->path() + "]");
            }
        } catch (const std::exception& e) {
            return grpc::Status(grpc::StatusCode::INTERNAL, e.what());
        } catch (...) {
            return grpc::Status(grpc::StatusCode::INTERNAL, "Unexpected error");
        }
        return Status::OK;
    }
};

void RunServer(const std::string& address) {
    FileTransferServiceImpl service;
    ServerBuilder builder;
    builder.AddListeningPort(address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << address << std::endl;
    server->Wait();
}

int main(int argc, char** argv) {
    std::string server_address = "0.0.0.0:50051"; // 默认地址

    if (argc > 1) {
        server_address = argv[1];
    } else {
        std::cout << "No address provided, using default: " << server_address << std::endl;
    }

    RunServer(server_address);
    return 0;
}