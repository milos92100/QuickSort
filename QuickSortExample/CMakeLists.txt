cmake_minimum_required(VERSION 3.3)
project(Quicksort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Quicksort/DisplayHandler.cpp
    Quicksort/DisplayHandler.h
    Quicksort/main.cpp
    Quicksort/ProccessHandler.cpp
    Quicksort/ProccessHandler.h
    Quicksort/QuicksortClass.cpp
    Quicksort/QuicksortClass.h
    Quicksort/Settings.cpp
    Quicksort/Settings.h)

add_executable(Quicksort ${SOURCE_FILES})