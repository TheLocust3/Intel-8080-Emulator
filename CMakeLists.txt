cmake_minimum_required(VERSION 2.8)
project(8080_Emulator)

set(CMAKE_CXX_STANDARD 99)

enable_testing()
add_subdirectory(tests)

set(SOURCE_FILES src/main.c src/registers.c src/registers.h src/common_functions.c src/common_functions.h src/ram.c src/ram.h src/opcodes/data_transfer.c src/opcodes/data_transfer.h src/cpu.c src/cpu.h src/matcher/matcher.c src/matcher/matcher.h src/matcher/instruction_template.c src/matcher/instruction_template.h src/opcode_definitions.c src/opcode_definitions.h src/opcodes/miscellaneous.c src/opcodes/miscellaneous.h src/flags.c src/flags.h src/opcodes/arithmetic/add.c src/opcodes/arithmetic/add.h)
add_executable(8080_Emulator ${SOURCE_FILES})
target_link_libraries(8080_Emulator m)
