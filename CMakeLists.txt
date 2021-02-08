cmake_minimum_required(VERSION 3.10)
project(exercise-moscow)
set(CMAKE_CXX_STANDARD 17)
add_library(moscow INTERFACE)
target_include_directories(moscow INTERFACE src)

add_subdirectory(test)