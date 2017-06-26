//
// Created by Jake Kinsella on 6/26/17.
//

#include <assert.h>
#include "../../src/opcodes/arithmetic/add.h"

void add_register_test();

const int TEST_VALUE1 = 10;
const int TEST_VALUE2 = 5;

int main(int argc, const char* argv[])
{
    add_register_test();

    return 0;
}

void add_register_test()
{
    a = TEST_VALUE1;
    b = TEST_VALUE2;

    add_register(b);

    assert(a == (TEST_VALUE1 + TEST_VALUE2) && "add_register_test failed!");

    assert(!is_zero_flag_set() && "add_register_test failed!");
    assert(!is_sign_flag_set() && "add_register_test failed!");
    assert(!is_parity_flag_set() && "add_register_test failed!"); // TODO: I just guessed on this
    assert(!is_carry_flag_set() && "add_register_test failed!"); // TODO: I just guessed on this
    assert(!is_aux_carry_flag_set() && "add_register_test failed!"); // TODO: I just guessed on this
}
