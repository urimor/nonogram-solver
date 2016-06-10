cmake_minimum_required(VERSION 3.5)
project(nonogram_solver)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp)
add_executable(nonogram_solver ${SOURCE_FILES})