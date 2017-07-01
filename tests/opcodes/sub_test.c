//
// Created by Jake Kinsella on 6/30/17.
//

#include <assert.h>
#include "../../src/registers.h"
#include "../../src/flags.h"
#include "../../src/opcodes/arithmetic/sub.h"

const int TEST_VALUE1 = 10;
const int TEST_VALUE2 = 5;

void generic_asserts();

void sub_register_test();
void sub_memory_test();

int main(int argc, const char* argv[])
{
    sub_register_test();
    sub_memory_test();

    return 0;
}

void sub_register_test()
{
    pc = 0;
    f = 0;
    a = TEST_VALUE1;
    b = TEST_VALUE2;

    sub_register(b);

    assert(a == (TEST_VALUE1 - TEST_VALUE2) && "sub_register_test failed!");
    assert(pc == 1 && "sub_register_test failed!");

    generic_asserts();
}

void sub_memory_test()
{
    pc = 0;
    f = 0;
    h = 0;
    l = 0;
    a = TEST_VALUE1;
    set_byte_from_address(0, TEST_VALUE2);

    sub_memory();

    assert(a == (TEST_VALUE1 - TEST_VALUE2) && "sub_memory_test failed!");
    assert(pc == 1 && "sub_memory_test failed!");

    generic_asserts();
}

void generic_asserts()
{
    assert(!is_zero_flag_set() && "generic_asserts failed!");
    assert(!is_sign_flag_set() && "generic_asserts failed!");
    assert(is_parity_flag_set() && "generic_asserts failed!");
    assert(!is_carry_flag_set() && "generic_asserts failed!");
    assert(!is_aux_carry_flag_set() && "generic_asserts failed!");
}
