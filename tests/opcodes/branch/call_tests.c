//
// Created by Jake Kinsella on 7/14/17.
//

#include <assert.h>
#include "../../../src/registers.h"
#include "../../../src/ram.h"
#include "../../../src/opcodes/branch/call.h"
#include "../../../src/opcodes/stack.h"
#include "../../../src/flags.h"

void generic_call_asserts();

void call_test();
void call_not_zero_test();
void call_zero_test();
void call_not_carry_test();
void call_carry_test();
void call_not_parity_test();
void call_parity_test();
void call_not_sign_test();
void call_sign_test();

const int TEST_ADDRESS = 10;
const int TEST_ADDRESS2 = 5;

int main(int argc, const char* argv[])
{
    call_test();
    call_not_zero_test();
    call_zero_test();
    call_not_carry_test();
    call_carry_test();
    call_not_parity_test();
    call_parity_test();
    call_not_sign_test();
    call_sign_test();

    return 0;
}

void call_test()
{
    pc = TEST_ADDRESS2;
    s = 0xFF;
    p = 0xFF;

    set_byte_from_address((uint16_t) (pc + 1), (uint8_t) TEST_ADDRESS);
    set_byte_from_address((uint16_t) (pc + 2), 0);

    call();

    assert(pc == 10 && "call_test failed!");
    generic_call_asserts();
}

void call_not_zero_test()
{
    pc = TEST_ADDRESS2;
    s = 0xFF;
    p = 0xFF;
    f = 0;
    set_zero_flag(false);

    set_byte_from_address((uint16_t) (pc + 1), (uint8_t) TEST_ADDRESS);
    set_byte_from_address((uint16_t) (pc + 2), 0);

    call_condition(CONDITIONAL_NZ);

    assert(pc == 10 && "call_not_zero_test failed!");
    generic_call_asserts();
}

void call_zero_test()
{
    pc = TEST_ADDRESS2;
    s = 0xFF;
    p = 0xFF;
    f = 0;
    set_zero_flag(true);

    set_byte_from_address((uint16_t) (pc + 1), (uint8_t) TEST_ADDRESS);
    set_byte_from_address((uint16_t) (pc + 2), 0);

    call_condition(CONDITIONAL_Z);

    assert(pc == 10 && "call_zero_test failed!");
    generic_call_asserts();
}

void call_not_carry_test()
{
    pc = TEST_ADDRESS2;
    s = 0xFF;
    p = 0xFF;
    f = 0;
    set_carry_flag(false);

    set_byte_from_address((uint16_t) (pc + 1), (uint8_t) TEST_ADDRESS);
    set_byte_from_address((uint16_t) (pc + 2), 0);

    call_condition(CONDITIONAL_NC);

    assert(pc == 10 && "call_not_zero_test failed!");
    generic_call_asserts();
}

void call_carry_test()
{
    pc = TEST_ADDRESS2;
    s = 0xFF;
    p = 0xFF;
    f = 0;
    set_carry_flag(true);

    set_byte_from_address((uint16_t) (pc + 1), (uint8_t) TEST_ADDRESS);
    set_byte_from_address((uint16_t) (pc + 2), 0);

    call_condition(CONDITIONAL_C);

    assert(pc == 10 && "call_carry_test failed!");
    generic_call_asserts();
}

void call_not_parity_test()
{
    pc = TEST_ADDRESS2;
    s = 0xFF;
    p = 0xFF;
    f = 0;
    set_parity_flag(false);

    set_byte_from_address((uint16_t) (pc + 1), (uint8_t) TEST_ADDRESS);
    set_byte_from_address((uint16_t) (pc + 2), 0);

    call_condition(CONDITIONAL_PO);

    assert(pc == 10 && "call_not_parity_test failed!");
    generic_call_asserts();
}

void call_parity_test()
{
    pc = TEST_ADDRESS2;
    s = 0xFF;
    p = 0xFF;
    f = 0;
    set_parity_flag(true);

    set_byte_from_address((uint16_t) (pc + 1), (uint8_t) TEST_ADDRESS);
    set_byte_from_address((uint16_t) (pc + 2), 0);

    call_condition(CONDITIONAL_PE);

    assert(pc == 10 && "call_parity_test failed!");
    generic_call_asserts();
}

void call_not_sign_test()
{
    pc = TEST_ADDRESS2;
    s = 0xFF;
    p = 0xFF;
    f = 0;
    set_sign_flag(false);

    set_byte_from_address((uint16_t) (pc + 1), (uint8_t) TEST_ADDRESS);
    set_byte_from_address((uint16_t) (pc + 2), 0);

    call_condition(CONDITIONAL_P);

    assert(pc == 10 && "call_not_sign_test failed!");
    generic_call_asserts();
}

void call_sign_test()
{
    pc = TEST_ADDRESS2;
    s = 0xFF;
    p = 0xFF;
    f = 0;
    set_sign_flag(true);

    set_byte_from_address((uint16_t) (pc + 1), (uint8_t) TEST_ADDRESS);
    set_byte_from_address((uint16_t) (pc + 2), 0);

    call_condition(CONDITIONAL_M);

    assert(pc == 10 && "call_sign_test failed!");
    generic_call_asserts();
}

void generic_call_asserts()
{
    assert(combine_bytes(s, p) == 0xFFFD && "generic_call_asserts failed!");
    assert(pop() == 0 && "generic_call_asserts failed!");
    assert(pop() == TEST_ADDRESS2 && "generic_call_asserts failed!");
}
