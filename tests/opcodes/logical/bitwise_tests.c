//
// Created by Jake Kinsella on 7/5/17.
//

#include <assert.h>
#include "../../../src/registers.h"
#include "../../../src/opcodes/logical/bitwise.h"
#include "../../../src/ram.h"

void generic_asserts_and();
void generic_asserts_xor();
void generic_asserts_or();

void and_register_test();
void and_memory_test();
void and_immediate_test();
void exclusive_or_register_test();
void exclusive_or_memory_test();
void exclusive_or_immediate_test();
void or_register_test();
void or_memory_test();
void or_immediate_test();
void rotate_left_test();
void rotate_right_test();
void rotate_left_through_carry_test();
void rotate_right_through_carry_test();

const int TEST_VALUE1 = 10;
const int TEST_VALUE2 = 9;

int main(int argc, const char* argv[])
{
    and_register_test();
    and_memory_test();
    and_immediate_test();

    exclusive_or_register_test();
    exclusive_or_memory_test();
    exclusive_or_immediate_test();

    or_register_test();
    or_memory_test();
    or_immediate_test();

    rotate_left_test();
    rotate_right_test();
    rotate_left_through_carry_test();
    rotate_right_through_carry_test();

    return 0;
}

void and_register_test()
{
    pc = 0;
    f = 0;
    a = TEST_VALUE1;
    b = TEST_VALUE2;

    and_register(b);

    assert(a == (TEST_VALUE1 & TEST_VALUE2) && "and_register_test failed!");
    assert(pc == 1 && "and_register_test failed!");

    generic_asserts_and();
}

void and_memory_test()
{
    pc = 0;
    f = 0;
    a = TEST_VALUE1;
    h = 0;
    l = 0;
    set_byte_from_address(0, TEST_VALUE2);

    and_memory();

    assert(a == (TEST_VALUE1 & TEST_VALUE2) && "and_memory_test failed!");
    assert(pc == 1 && "and_memory_test failed!");

    generic_asserts_and();
}

void and_immediate_test()
{
    pc = 0;
    f = 0;
    a = TEST_VALUE1;
    set_byte_from_address(1, TEST_VALUE2);

    and_immediate();

    assert(a == (TEST_VALUE1 & TEST_VALUE2) && "and_immediate_test failed!");
    assert(pc == 2 && "and_immediate_test failed!");

    generic_asserts_and();
    assert(!get_aux_carry_flag() && "and_immediate_test failed!");
}

void exclusive_or_register_test()
{
    pc = 0;
    f = 0;
    a = TEST_VALUE1;
    b = TEST_VALUE2;

    exclusive_or_register(b);

    assert(a == (TEST_VALUE1 ^ TEST_VALUE2) && "exclusive_or_register_test failed!");
    assert(pc == 1 && "exclusive_or_register_test failed!");

    generic_asserts_xor();
}

void exclusive_or_memory_test()
{
    pc = 0;
    f = 0;
    a = TEST_VALUE1;
    h = 0;
    l = 0;
    set_byte_from_address(0, TEST_VALUE2);

    exclusive_or_memory();

    assert(a == (TEST_VALUE1 ^ TEST_VALUE2) && "exclusive_or_memory_test failed!");
    assert(pc == 1 && "exclusive_or_memory_test failed!");

    generic_asserts_xor();
}

void exclusive_or_immediate_test()
{
    pc = 0;
    f = 0;
    a = TEST_VALUE1;
    set_byte_from_address(1, TEST_VALUE2);

    exclusive_or_immediate();

    assert(a == (TEST_VALUE1 ^ TEST_VALUE2) && "exclusive_or_immediate_test failed!");
    assert(pc == 2 && "exclusive_or_immediate_test failed!");

    generic_asserts_xor();
}

void or_register_test()
{
    pc = 0;
    f = 0;
    a = TEST_VALUE1;
    b = TEST_VALUE2;

    or_register(b);

    assert(a == (TEST_VALUE1 | TEST_VALUE2) && "or_register_test failed!");
    assert(pc == 1 && "or_register_test failed!");

    generic_asserts_or();
}

void or_memory_test()
{
    pc = 0;
    f = 0;
    a = TEST_VALUE1;
    h = 0;
    l = 0;
    set_byte_from_address(0, TEST_VALUE2);

    or_memory();

    assert(a == (TEST_VALUE1 | TEST_VALUE2) && "or_memory_test failed!");
    assert(pc == 1 && "or_memory_test failed!");

    generic_asserts_or();
}

void or_immediate_test()
{
    pc = 0;
    f = 0;
    a = TEST_VALUE1;
    set_byte_from_address(1, TEST_VALUE2);

    or_immediate();

    assert(a == (TEST_VALUE1 | TEST_VALUE2) && "or_immediate_test failed!");
    assert(pc == 2 && "or_immediate_test failed!");

    generic_asserts_or();
}

void rotate_left_test()
{
    pc = 0;
    f = 0;
    a = TEST_VALUE1;

    rotate_left();

    assert(a == (TEST_VALUE1 << 1) && "rotate_left_test failed!");
    assert(pc == 1 && "rotate_left_test failed!");

    assert(!get_carry_flag() && "rotate_left_test failed!");
}

void rotate_right_test()
{
    pc = 0;
    f = 0;
    a = TEST_VALUE1;

    rotate_right();

    assert(a == (TEST_VALUE1 >> 1) && "rotate_right_test failed!");
    assert(pc == 1 && "rotate_right_test failed!");

    assert(!get_carry_flag() && "rotate_right_test failed!");
}

void rotate_left_through_carry_test()
{
    pc = 0;
    f = 0;
    a = TEST_VALUE1;
    set_carry_flag(true);

    rotate_left_through_carry();

    assert(a == (TEST_VALUE1 << 1) + 1 && "rotate_left_through_carry_test failed!");
    assert(pc == 1 && "rotate_left_through_carry_test failed!");

    assert(!get_carry_flag() && "rotate_left_through_carry_test failed!");
}

void rotate_right_through_carry_test()
{
    pc = 0;
    f = 0;
    a = TEST_VALUE1;
    set_carry_flag(true);

    rotate_right_through_carry();

    assert(a == ((TEST_VALUE1 >> 1) + 128) && "rotate_right_through_carry_test failed!");
    assert(pc == 1 && "rotate_right_through_carry_test failed!");

    assert(!get_carry_flag() && "rotate_right_through_carry_test failed!");
}

void generic_asserts_and()
{
    assert(!get_zero_flag() && "generic_asserts_and failed");
    assert(!get_sign_flag() && "generic_asserts_and failed");
    assert(!get_parity_flag() && "generic_asserts_and failed");
    assert(!get_carry_flag() && "generic_asserts_and failed");
    //assert(!get_aux_carry_flag() && "generic_asserts_and failed"); // currently incorrect
}

void generic_asserts_xor()
{
    assert(!get_zero_flag() && "generic_asserts_xor failed");
    assert(!get_sign_flag() && "generic_asserts_xor failed");
    assert(get_parity_flag() && "generic_asserts_xor failed");
    assert(!get_carry_flag() && "generic_asserts_xor failed");
    assert(!get_aux_carry_flag() && "generic_asserts_and failed");
}

void generic_asserts_or()
{
    assert(!get_zero_flag() && "generic_asserts_or failed");
    assert(!get_sign_flag() && "generic_asserts_or failed");
    assert(!get_parity_flag() && "generic_asserts_or failed");
    assert(!get_carry_flag() && "generic_asserts_or failed");
    assert(!get_aux_carry_flag() && "generic_asserts_or failed");
}
