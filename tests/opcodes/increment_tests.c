//
// Created by Jake Kinsella on 7/2/17.
//

#include <assert.h>
#include "../../src/registers.h"
#include "../../src/flags.h"
#include "../../src/opcodes/arithmetic/increment.h"

void generic_asserts_increment();
void generic_asserts_decrement();

void increment_register_test();
void increment_memory_test();
void decrement_register_test();
void decrement_memory_test();
void increment_register_pair_test();

const int TEST_VALUE1 = 10;

int main(int argc, const char* argv[])
{
    increment_register_test();
    increment_memory_test();
    decrement_register_test();
    decrement_memory_test();
    increment_register_pair_test();

    return 0;
}

void increment_register_test()
{
    pc = 0;
    f = 0;
    a = TEST_VALUE1;

    increment_register(&a);

    assert(a == (TEST_VALUE1 + 1) && "increment_register_test failed!");
    assert(pc == 1 && "increment_register_test failed!");

    generic_asserts_increment();
}

void increment_memory_test()
{
    pc = 0;
    f = 0;
    h = 0;
    l = 0;
    set_byte(h, l, TEST_VALUE1);

    increment_memory();

    assert(read_byte(h, l) == (TEST_VALUE1 + 1) && "increment_memory_test failed!");
    assert(pc == 1 && "increment_memory_test failed!");

    generic_asserts_increment();
}

void increment_register_pair_test()
{
    pc = 0;
    f = 0;
    h = 0;
    l = TEST_VALUE1;

    increment_register_pair(create_register_pair(&h, &l));
    
    assert(h == 0 && l == (TEST_VALUE1 + 1) && "increment_register_pair_test failed!");
    assert(pc == 1 && "increment_register_pair_test failed!");
}

void decrement_register_test()
{
    pc = 0;
    f = 0;
    a = TEST_VALUE1;

    decrement_register(&a);

    assert(a == (TEST_VALUE1 - 1) && "decrement_register_test failed!");
    assert(pc == 1 && "decrement_register_test failed!");

    generic_asserts_decrement();
}

void decrement_memory_test()
{
    pc = 0;
    f = 0;
    h = 0;
    l = 0;
    set_byte(h, l, TEST_VALUE1);

    decrement_memory();

    assert(read_byte(h, l) == (TEST_VALUE1 - 1) && "decrement_memory_test failed!");
    assert(pc == 1 && "decrement_memory_test failed!");

    generic_asserts_decrement();
}

void generic_asserts_increment()
{
    assert(!is_zero_flag_set() && "generic_asserts_increment failed!");
    assert(!is_sign_flag_set() && "generic_asserts_increment failed!");
    assert(!is_parity_flag_set() && "generic_asserts_increment failed!");
    assert(!is_aux_carry_flag_set() && "generic_asserts_increment failed!");
}

void generic_asserts_decrement()
{
    assert(!is_zero_flag_set() && "generic_asserts_decrement failed!");
    assert(!is_sign_flag_set() && "generic_asserts_decrement failed!");
    assert(is_parity_flag_set() && "generic_asserts_decrement failed!");
    assert(!is_aux_carry_flag_set() && "generic_asserts_decrement failed!");
}
