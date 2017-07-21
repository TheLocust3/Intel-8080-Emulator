//
// Created by Jake Kinsella on 6/10/17.
//

#include <assert.h>
#include "../../src/opcodes/data_transfer.h"
#include "../../src/ram.h"
#include "../../src/common_functions.h"

void move_register_test();
void move_from_memory_test();
void move_to_memory_test();
void move_immediate_test();
void move_to_memory_immediate_test();
void load_register_pair_immediate_test();
void load_accumulator_direct_test();
void store_accumulator_direct_test();
void load_HL_direct_test();
void store_HL_direct_test();
void load_accumulator_indirect_test();
void store_accumulator_indirect_test();
void exchange_HL_DE_test();

const int TEST_VALUE1 = 10;

int main(int argc, const char* argv[])
{
    move_register_test();
    move_from_memory_test();
    move_to_memory_test();
    move_immediate_test();
    move_to_memory_immediate_test();
    load_register_pair_immediate_test();
    load_accumulator_direct_test();
    store_accumulator_direct_test();
    load_HL_direct_test();
    store_HL_direct_test();
    load_accumulator_indirect_test();
    store_accumulator_indirect_test();
    exchange_HL_DE_test();

    return 0;
}

void move_register_test()
{
    a = 0;
    b = TEST_VALUE1;
    move_register(&a, b);

    assert(a == b && "Move_register_test failed!");
    assert(pc == 1 && "move_register_test failed!");
}

void move_from_memory_test()
{
    pc = 0;
    a = 0;
    h = 0;
    l = 0;
    set_byte(h, l, TEST_VALUE1);

    move_from_memory(&a);

    assert(a == TEST_VALUE1 && "move_from_memory_test failed!");
    assert(pc == 1 && "move_from_memory_test failed!");
}

void move_to_memory_test()
{
    pc = 0;
    a = TEST_VALUE1;
    h = 0;
    l = 0;

    move_to_memory(a);

    assert(read_byte(h, l) == TEST_VALUE1 && "move_to_memory_test failed!");
    assert(pc == 1 && "move_to_memory_test failed!");
}

void move_immediate_test()
{
    a = 0;
    pc = 0;

    set_byte_from_address((uint16_t) (pc + 1), TEST_VALUE1);

    move_immediate(&a);

    assert(a == TEST_VALUE1 && "move_immediate_test failed!");
    assert(pc == 2 && "move_immediate_test failed!");
}

void move_to_memory_immediate_test()
{
    h = 0;
    l = 0;
    pc = 0;

    set_byte_from_address((uint16_t) (pc + 1), TEST_VALUE1);

    move_to_memory_immediate();

    assert(read_byte(h, l) == TEST_VALUE1 && "move_to_memory_immediate_test failed!");
    assert(pc == 2 && "move_to_memory_immediate_test failed!");

}

void load_register_pair_immediate_test()
{
    h = 0;
    l = 0;
    pc = 0;

    set_byte_from_address((uint16_t) (pc + 2), 0);
    set_byte_from_address((uint16_t) (pc + 1), TEST_VALUE1);

    RegisterPair register_pair = get_register_pair_from_code(HL_CODE);
    load_register_pair_immediate(&register_pair);

    assert(does_register_pair_equal(get_register_pair_from_code(HL_CODE), TEST_VALUE1) && "load_register_pair_immediate_test failed!");
    assert(pc == 3 && "load_register_pair_immediate_test failed!");
}

void load_accumulator_direct_test()
{
    a = 0;
    pc = 0;

    set_byte_from_address(0, TEST_VALUE1);
    set_byte_from_address((uint16_t) (pc + 2), 0);
    set_byte_from_address((uint16_t) (pc + 1), 0);

    load_accumulator_direct();

    assert(a == TEST_VALUE1 && "load_accumulator_direct_test failed!");
    assert(pc == 3 && "load_accumulator_direct_test failed!");
}

void store_accumulator_direct_test()
{
    a = TEST_VALUE1;
    pc = 0;
    set_byte_from_address(0, 0);

    set_byte_from_address((uint16_t) (pc + 2), 0);
    set_byte_from_address((uint16_t) (pc + 1), 0);

    store_accumulator_direct();

    assert(read_byte_from_address(0) == TEST_VALUE1 && "store_accumulator_direct_test failed!");
    assert(pc == 3 && "store_accumulator_direct_test failed!");
}

void load_HL_direct_test()
{
    h = 0;
    l = 0;
    pc = 0;
    set_byte_from_address(10, TEST_VALUE1);
    set_byte_from_address(11, 0);

    set_byte_from_address((uint16_t) (pc + 2), 0);
    set_byte_from_address((uint16_t) (pc + 1), 10);

    load_HL_direct();

    assert(combine_bytes(h, l) == TEST_VALUE1 && "load_HL_direct_test failed!");
    assert(pc == 3 && "load_HL_direct_test failed!");
}

void store_HL_direct_test()
{
    h = TEST_VALUE1;
    l = TEST_VALUE1;
    pc = 0;

    set_byte_from_address((uint16_t) (pc + 2), 0);
    set_byte_from_address((uint16_t) (pc + 1), 10);

    store_HL_direct();

    assert(read_byte_from_address(10) == TEST_VALUE1 && read_byte_from_address(11) == TEST_VALUE1 && "store_HL_direct_test failed!");
    assert(pc == 3 && "store_HL_direct_test failed!");
}

void load_accumulator_indirect_test()
{
    a = 0;
    h = 0;
    l = 0;
    pc = 0;

    set_byte_from_address(0, TEST_VALUE1);
    RegisterPair register_pair = create_register_pair(&h, &l);

    load_accumulator_indirect(register_pair);

    assert(a == TEST_VALUE1 && "load_accumulator_indirect_test failed!");
    assert(pc == 1 && "load_accumulator_indirect_test failed!");
}

void store_accumulator_indirect_test()
{
    a = TEST_VALUE1;
    h = 0;
    l = 0;
    pc = 0;

    set_byte_from_address(0, 0);
    RegisterPair register_pair = create_register_pair(&h, &l);

    store_accumulator_indirect(register_pair);

    assert(read_byte_from_address(0) == TEST_VALUE1 && "store_accumulator_indirect_test failed!");
    assert(pc == 1 && "store_accumulator_indirect_test failed!");
}

void exchange_HL_DE_test()
{
    pc = 0;

    h = 0;
    l = TEST_VALUE1;

    d = TEST_VALUE1;
    e = 0;

    exchange_HL_DE();

    assert(h == TEST_VALUE1 && l == 0 && d == 0 && e == TEST_VALUE1 && "exchange_HL_DE_test failed!");
    assert(pc == 1 && "exchange_HL_DE_test failed!");
}
