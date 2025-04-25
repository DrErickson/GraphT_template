cmake_minimum_required(VERSION 3.27)
project(GraphT)

set(CMAKE_CXX_STANDARD 11)

add_executable(GraphBasicTest main.cpp GraphT.h)

add_executable(TraversalTest TraverseTests.cpp GraphT.h)
