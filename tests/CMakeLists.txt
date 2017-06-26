enable_testing()

add_executable(data_transfer_tests ../src/common_functions.c ../src/ram.c ../src/registers.c ../src/opcodes/data_transfer.c opcodes/data_transfer_tests.c)
add_executable(add_tests ../src/common_functions.c ../src/ram.c ../src/registers.c ../src/flags.c ../src/opcodes/arithmetic/add.c opcodes/add_tests.c)
add_executable(miscellaneous_tests ../src/common_functions.c ../src/ram.c ../src/registers.c ../src/opcodes/miscellaneous.c opcodes/miscellaneous_tests.c)

add_executable(matcher_tests ../src/common_functions.c ../src/registers.c ../src/matcher/instruction_template.c ../src/matcher/matcher.c matcher/matcher_tests.c)
add_executable(instruction_template_tests ../src/matcher/instruction_template.c matcher/instruction_template_tests.c)
add_executable(matcher_simple_run_tests ../src/common_functions.c ../src/registers.c ../src/matcher/instruction_template.c ../src/matcher/matcher.c matcher/matcher_simple_run_tests.c)
add_executable(matcher_argument_run_tests ../src/common_functions.c ../src/registers.c ../src/matcher/instruction_template.c ../src/matcher/matcher.c matcher/matcher_argument_run_tests.c)

target_link_libraries(matcher_tests m)
target_link_libraries(instruction_template_tests m)
target_link_libraries(matcher_simple_run_tests m)
target_link_libraries(matcher_argument_run_tests m)

add_test(data_transfer_tests data_transfer_tests)
add_test(add_tests add_tests)
add_test(miscellaneous_tests miscellaneous_tests)

add_test(matcher_tests matcher_tests)
add_test(instruction_template_tests instruction_template_tests)
add_test(matcher_simple_run_tests matcher_simple_run_tests)
add_test(matcher_argument_run_tests matcher_argument_run_tests)
