enable_testing()

add_executable(data_transfer_tests ../src/common_functions.c ../src/ram.c ../src/opcodes/data_transfer.c data_transfer_tests.c)

add_test(data_transfer_tests data_transfer_tests)
