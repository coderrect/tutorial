cmake_minimum_required(VERSION 3.10)
project(ringbuffer)
set(CMAKE_CXX_STANDARD 11)
find_package(Threads)
add_library(ringbuffer STATIC
            ringbuffer_lib.cpp
            ringbuffer_lib.h)
