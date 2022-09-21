cmake_minimum_required(VERSION 3.22)
project(OptimizationAlgorithm)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(OptimizationAlgorithm
        src/main.cpp
        src/makeBigFile.h
        src/OptAlgorithm.cpp
        src/OptAlgorithm.h)
