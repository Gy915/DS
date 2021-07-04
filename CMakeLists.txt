cmake_minimum_required(VERSION 3.19)
project(DS)

set(CMAKE_CXX_STANDARD 14)

include_directories(SeqList)

add_executable(SeqList
        SeqList/main.cpp
        SeqList/List.cpp
        SeqList/List.h)
