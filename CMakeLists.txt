cmake_minimum_required(VERSION 3.19)
project(DS)

set(CMAKE_CXX_STANDARD 14)

include_directories(tree)

add_executable(DS
        tree/main.cpp
        tree/tree.cpp
        tree/tree.h)
