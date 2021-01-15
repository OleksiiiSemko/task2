cmake_minimum_required(VERSION 3.17)
project(task2)

add_subdirectory(Google_tests)
set(CMAKE_CXX_STANDARD 14)

add_executable(task2 main.cpp AnyType.cpp utils.cpp)
