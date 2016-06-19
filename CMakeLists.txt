cmake_minimum_required(VERSION 3.5)
project(nonogram_solver)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(SOURCE_FILES src/main.cpp src/PuzzleSquare.h src/Board.cpp src/Board.h src/NonogramSolver.cpp src/NonogramSolver.h src/Common.cpp src/Common.h)
add_executable(nonogram_solver ${SOURCE_FILES})
include_directories(3rdParty)
