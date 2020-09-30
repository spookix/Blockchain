cmake_minimum_required(VERSION 3.15)
project(Blockchain)

set(CMAKE_CXX_STANDARD 14)

add_executable(Blockchain main.cpp Block.cpp Block.h Blockchain.cpp Blockchain.h sha256.cpp sha256.h Encryption.cpp Encryption.h)