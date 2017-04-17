cmake_minimum_required(VERSION 3.6)
project(8080_Emulator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c registers.c registers.h common_functions.c common_functions.h ram.c ram.h)
add_executable(8080_Emulator ${SOURCE_FILES})