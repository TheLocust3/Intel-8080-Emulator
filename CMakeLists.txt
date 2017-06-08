cmake_minimum_required(VERSION 3.6)
project(8080_Emulator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.c src/registers.c src/registers.h src/common_functions.c src/common_functions.h src/ram.c src/ram.h src/opcodes/data_transfer.c src/opcodes/data_transfer.h src/cpu.c src/cpu.h src/handlers/data_transfer_handler.c src/handlers/data_transfer_handler.h src/matcher/matcher.c src/matcher/matcher.h src/matcher/instruction_template.c src/matcher/instruction_template.h)
add_executable(8080_Emulator ${SOURCE_FILES})