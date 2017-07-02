//
// Created by Jake Kinsella on 7/2/17.
//

#include <assert.h>
#include "../../src/registers.h"
#include "../../src/flags.h"
#include "../../src/opcodes/arithmetic/increment.h"

void generic_asserts_increment();

void increment_register_test();

const int TEST_VALUE1 = 10;

int main(int argc, const char* argv[])
{
    increment_register_test();

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

void generic_asserts_increment()
{
    assert(!is_zero_flag_set() && "generic_asserts_increment failed!");
    assert(!is_sign_flag_set() && "generic_asserts_increment failed!");
    assert(!is_parity_flag_set() && "generic_asserts_increment failed!");
    assert(!is_aux_carry_flag_set() && "generic_asserts_increment failed!");
}
