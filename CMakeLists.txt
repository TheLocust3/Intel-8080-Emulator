cmake_minimum_required(VERSION 2.8)
project(8080_Emulator)

set(CMAKE_CXX_STANDARD 99)

enable_testing()
add_subdirectory(tests)

set(SOURCE_FILES src/main.c src/registers.c src/registers.h src/common_functions.c src/common_functions.h src/ram.c src/ram.h src/opcodes/data_transfer.c src/opcodes/data_transfer.h src/cpu.c src/cpu.h src/matcher/matcher.c src/matcher/matcher.h src/matcher/instruction_template.c src/matcher/instruction_template.h src/opcode_definitions.c src/opcode_definitions.h src/opcodes/miscellaneous.c src/opcodes/miscellaneous.h src/flags.c src/flags.h src/opcodes/arithmetic/add.c src/opcodes/arithmetic/add.h src/opcodes/arithmetic/sub.c src/opcodes/arithmetic/sub.h src/opcodes/arithmetic/increment.c src/opcodes/arithmetic/increment.h src/opcodes/arithmetic/miscellaneous_arithmetic.c src/opcodes/arithmetic/miscellaneous_arithmetic.h src/opcodes/logical/bitwise.c src/opcodes/logical/bitwise.h src/opcodes/logical/miscellaneous_logical.c src/opcodes/logical/miscellaneous_logical.h src/opcodes/branch/jump.c src/opcodes/branch/jump.h src/opcodes/branch/call.c src/opcodes/branch/call.h src/opcodes/stack.c src/opcodes/stack.h src/opcodes/branch/miscellaneous_branch.c src/opcodes/branch/miscellaneous_branch.h src/pins/data_bus.c src/pins/data_bus.h src/pins/address_bus.c src/pins/address_bus.h src/pins/pins.c src/pins/pins.h src/log.c src/log.h)
add_executable(8080_Emulator ${SOURCE_FILES})
target_link_libraries(8080_Emulator m)
