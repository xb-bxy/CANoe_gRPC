cmake_minimum_required(VERSION 3.10)

project(FileTransfer)
SET(CMAKE_BUILD_TYPE "Debug")
# 设置 C++ 标准为 C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 查找 gRPC 和 Protocol Buffers
find_package(PkgConfig REQUIRED)
pkg_check_modules(GRPC REQUIRED grpc)
pkg_check_modules(Protobuf REQUIRED protobuf)

# 设置 gRPC 和 Protocol Buffers 的路径
include_directories(${GRPC_INCLUDE_DIRS})
include_directories(${Protobuf_INCLUDE_DIRS})

link_directories(${GRPC_LIBRARY_DIRS})
link_directories(${Protobuf_LIBRARY_DIRS})

# 将 proto 文件路径添加到变量中
set(PROTO_DIR ${CMAKE_SOURCE_DIR}/proto)
set(PROTO_FILE ${PROTO_DIR}/file_transfer.proto)

# 生成 gRPC 和 protobuf 相关文件
find_program(GRPC_CPP_PLUGIN grpc_cpp_plugin HINTS /usr/local/bin /usr/bin)  # 手动指定路径

add_custom_command(
    OUTPUT ${CMAKE_SOURCE_DIR}/src/file_transfer.pb.cc ${CMAKE_SOURCE_DIR}/src/file_transfer.pb.h
    COMMAND protoc
    ARGS --cpp_out=${CMAKE_SOURCE_DIR}/src --proto_path=${PROTO_DIR} ${PROTO_FILE}
    DEPENDS ${PROTO_FILE}
)

add_custom_command(
    OUTPUT ${CMAKE_SOURCE_DIR}/src/file_transfer.grpc.pb.cc ${CMAKE_SOURCE_DIR}/src/file_transfer.grpc.pb.h
    COMMAND protoc
    ARGS --grpc_out=${CMAKE_SOURCE_DIR}/src --plugin=protoc-gen-grpc=${GRPC_CPP_PLUGIN} --proto_path=${PROTO_DIR} ${PROTO_FILE}
    DEPENDS ${PROTO_FILE}
)

# 源文件
set(SOURCES
    src/file_transfer.pb.cc
    src/file_transfer.grpc.pb.cc
)

# 添加可执行文件
add_executable(client src/client.cpp ${SOURCES})
add_executable(server src/server.cpp ${SOURCES})

# 链接库
target_link_libraries(client ${GRPC_LIBRARIES} ${Protobuf_LIBRARIES} grpc++ protobuf)
target_link_libraries(server ${GRPC_LIBRARIES} ${Protobuf_LIBRARIES} grpc++ protobuf)

# 打印信息
message(STATUS "gRPC_INCLUDE_DIRS = ${GRPC_INCLUDE_DIRS}")
message(STATUS "gRPC_LIBRARIES = ${GRPC_LIBRARIES}")
message(STATUS "Protobuf_INCLUDE_DIRS = ${Protobuf_INCLUDE_DIRS}")
message(STATUS "Protobuf_LIBRARIES = ${Protobuf_LIBRARIES}")
message(STATUS "GRPC_CPP_PLUGIN = ${GRPC_CPP_PLUGIN}")
