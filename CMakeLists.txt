cmake_minimum_required(VERSION 3.19)
project(DS)

set(CMAKE_CXX_STANDARD 14)

include_directories(Tree1)

add_executable(tree
        Tree1/main.cpp
        Tree1/tree.cpp
        Tree1/tree.h)
