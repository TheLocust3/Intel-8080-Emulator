//
// Created by Jake Kinsella on 6/26/17.
//

#include <assert.h>
#include "../../src/opcodes/arithmetic/add.h"
#include "../../src/ram.h"

void generic_asserts();

void add_register_test();
void add_memory_test();

const int TEST_VALUE1 = 10;
const int TEST_VALUE2 = 5;

int main(int argc, const char* argv[])
{
    add_register_test();
    add_memory_test();

    return 0;
}

void add_register_test()
{
    f = 0;
    a = TEST_VALUE1;
    b = TEST_VALUE2;

    add_register(b);

    assert(a == (TEST_VALUE1 + TEST_VALUE2) && "add_register_test failed!");

    generic_asserts();
}

void add_memory_test()
{
    f = 0;
    h = 0;
    l = 0;
    a = TEST_VALUE1;
    set_byte_from_address(0, TEST_VALUE2);

    add_register(b);

    assert(a == (TEST_VALUE1 + TEST_VALUE2) && "add_memory_test failed!");

    generic_asserts();
}

void generic_asserts()
{
    assert(!is_zero_flag_set() && "add_memory_test failed!");
    assert(!is_sign_flag_set() && "add_memory_test failed!");
    assert(is_parity_flag_set() && "add_memory_test failed!");
    assert(!is_carry_flag_set() && "add_memory_test failed!");
    assert(!is_aux_carry_flag_set() && "add_memory_test failed!");
}
