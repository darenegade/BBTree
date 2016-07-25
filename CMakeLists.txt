cmake_minimum_required(VERSION 3.4)
project(AlgDat2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES BBTree.cpp)
add_executable(BBTree ${SOURCE_FILES})
