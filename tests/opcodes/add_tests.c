//
// Created by Jake Kinsella on 6/26/17.
//

#include <assert.h>
#include <stdlib.h>
#include "../../src/opcodes/arithmetic/add.h"
#include "../../src/ram.h"

void generic_asserts();

void add_register_test();
void add_memory_test();
void add_immediate_test();
void add_register_with_carry_test();

const int TEST_VALUE1 = 10;
const int TEST_VALUE2 = 5;

int main(int argc, const char* argv[])
{
    add_register_test();
    add_memory_test();
    add_immediate_test();
    add_register_with_carry_test();

    return 0;
}

void add_register_test()
{
    pc = 0;
    f = 0;
    a = TEST_VALUE1;
    b = TEST_VALUE2;

    add_register(b);

    assert(a == (TEST_VALUE1 + TEST_VALUE2) && "add_register_test failed!");
    assert(pc == 1 && "add_register_test failed!");

    generic_asserts();
}

void add_memory_test()
{
    pc = 0;
    f = 0;
    h = 0;
    l = 0;
    a = TEST_VALUE1;
    set_byte_from_address(0, TEST_VALUE2);

    add_memory();

    assert(a == (TEST_VALUE1 + TEST_VALUE2) && "add_memory_test failed!");
    assert(pc == 1 && "add_memory_test failed!");

    generic_asserts();
}

void add_immediate_test()
{
    pc = 0;
    f = 0;
    a = TEST_VALUE1;
    set_byte_from_address(1, TEST_VALUE2);

    add_immediate();

    assert(a == (TEST_VALUE1 + TEST_VALUE2) && "add_memory_test failed!");
    assert(pc == 2 && "add_immediate_test failed!");

    generic_asserts();
}

void add_register_with_carry_test()
{
    pc = 0;
    f = 0;
    a = TEST_VALUE1;
    b = TEST_VALUE2;
    set_carry_flag(true);

    add_register_with_carry(b);

    assert(a == (TEST_VALUE1 + TEST_VALUE2 + 1) && "add_register_with_carry_test failed!");
    assert(pc == 1 && "add_register_with_carry_test failed!");

    assert(!is_zero_flag_set() && "add_register_with_carry_test failed!");
    assert(!is_sign_flag_set() && "add_register_with_carry_test failed!");
    assert(!is_parity_flag_set() && "add_register_with_carry_test failed!");
    assert(!is_carry_flag_set() && "add_register_with_carry_test failed!");
    assert(is_aux_carry_flag_set() && "add_register_with_carry_test failed!");
}

void generic_asserts()
{
    assert(!is_zero_flag_set() && "generic_asserts failed!");
    assert(!is_sign_flag_set() && "generic_asserts failed!");
    assert(is_parity_flag_set() && "generic_asserts failed!");
    assert(!is_carry_flag_set() && "generic_asserts failed!");
    assert(!is_aux_carry_flag_set() && "generic_asserts failed!");
}
