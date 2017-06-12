//
// Created by Jake Kinsella on 6/10/17.
//

#include <stdio.h>
#include "../src/opcodes/data_transfer.h"
#include "../src/registers.h"
#include "../src/ram.h"

int move_register_test();
int move_from_memory_test();
int move_to_memory_test();
int move_immediate_test();
int move_to_memory_immediate_test();
int load_register_pair_immediate_test();
int load_accumulator_direct_test();

const int TEST_VALUE = 10;

int main(int argc, const char* argv[])
{
    int status = move_register_test();
    status = status && move_from_memory_test();
    status = status && move_to_memory_test();
    status = status && move_immediate_test();
    status = status && move_to_memory_immediate_test();
    status = status && load_register_pair_immediate_test();
    status = status && load_accumulator_direct_test();

    return !status;
}

int move_register_test()
{
    a = 0;
    b = TEST_VALUE;
    move_register(&a, b);

    return a == b;
}

int move_from_memory_test()
{
    a = 0;
    h = 0;
    l = 0;
    set_byte(h, l, TEST_VALUE);

    move_from_memory(&a);

    return a == TEST_VALUE;
}

int move_to_memory_test()
{
    a = TEST_VALUE;
    h = 0;
    l = 0;

    move_to_memory(a);

    return read_byte(h, l) == TEST_VALUE;
}

int move_immediate_test()
{
    a = 0;
    pc = 0;

    set_byte_from_address((uint16_t) (pc + 1), TEST_VALUE);

    move_immediate(&a);

    return a == TEST_VALUE;
}

int move_to_memory_immediate_test()
{
    h = 0;
    l = 0;
    pc = 0;

    set_byte_from_address((uint16_t) (pc + 1), TEST_VALUE);

    move_to_memory_immediate();

    return read_byte(h, l) == TEST_VALUE;
}

int load_register_pair_immediate_test()
{
    h = 0;
    l = 0;
    pc = 0;

    set_byte_from_address((uint16_t) (pc + 2), 0);
    set_byte_from_address((uint16_t) (pc + 1), TEST_VALUE);

    uint16_t register_pair = get_register_pair_from_code(HL_CODE);
    load_register_pair_immediate(&register_pair);

    return get_register_from_code(HL_CODE) == TEST_VALUE;
}

int load_accumulator_direct_test()
{
    a = 0;
    pc = 0;

    set_byte_from_address(0, TEST_VALUE);
    set_byte_from_address((uint16_t) (pc + 2), 0);
    set_byte_from_address((uint16_t) (pc + 1), 0);

    load_accumulator_direct();

    return a == TEST_VALUE;
}
