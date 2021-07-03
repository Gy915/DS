cmake_minimum_required(VERSION 3.19)
project(DS)

set(CMAKE_CXX_STANDARD 14)

include_directories(Node1)

add_executable(node
        Node1/main.cpp
        Node1/node.cpp
        Node1/node.h)
