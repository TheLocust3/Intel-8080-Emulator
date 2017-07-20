//
// Created by Jake Kinsella on 7/11/17.
//

#include <assert.h>
#include "../../../src/registers.h"
#include "../../../src/ram.h"
#include "../../../src/opcodes/branch/jump.h"
#include "../../../src/flags.h"

void jump_test();
void jump_not_zero_test();
void jump_zero_test();
void jump_not_carry_test();
void jump_carry_test();
void jump_not_parity_test();
void jump_parity_test();
void jump_not_sign_test();
void jump_sign_test();

const int TEST_ADDRESS = 10;

int main(int argc, const char* argv[])
{
    jump_test();
    jump_not_zero_test();
    jump_zero_test();
    jump_not_carry_test();
    jump_carry_test();
    jump_not_parity_test();
    jump_parity_test();
    jump_not_sign_test();
    jump_sign_test();

    return 0;
}

void jump_test()
{
    pc = 0;

    set_byte_from_address((uint16_t) (pc + 1), (uint8_t) TEST_ADDRESS);
    set_byte_from_address((uint16_t) (pc + 2), 0);

    jump();

    assert(pc == TEST_ADDRESS && "jump_test failed!");
}

void jump_not_zero_test()
{
    pc = 0;
    f = 0;
    set_zero_flag(false);

    set_byte_from_address((uint16_t) (pc + 1), (uint8_t) TEST_ADDRESS);
    set_byte_from_address((uint16_t) (pc + 2), 0);

    jump_condition(CONDITIONAL_NZ);

    assert(pc == TEST_ADDRESS && "jump_not_zero_test failed!");
}

void jump_zero_test()
{
    pc = 0;
    set_zero_flag(true);

    set_byte_from_address((uint16_t) (pc + 1), (uint8_t) TEST_ADDRESS);
    set_byte_from_address((uint16_t) (pc + 2), 0);

    jump_condition(CONDITIONAL_Z);

    assert(pc == TEST_ADDRESS && "jump_zero_test failed!");
}

void jump_not_carry_test()
{
    pc = 0;
    f = 0;
    set_carry_flag(false);

    set_byte_from_address((uint16_t) (pc + 1), (uint8_t) TEST_ADDRESS);
    set_byte_from_address((uint16_t) (pc + 2), 0);

    jump_condition(CONDITIONAL_NC);

    assert(pc == TEST_ADDRESS && "jump_not_carry_test failed!");
}

void jump_carry_test()
{
    pc = 0;
    f = 0;
    set_carry_flag(true);

    set_byte_from_address((uint16_t) (pc + 1), (uint8_t) TEST_ADDRESS);
    set_byte_from_address((uint16_t) (pc + 2), 0);

    jump_condition(CONDITIONAL_C);

    assert(pc == TEST_ADDRESS && "jump_carry_test failed!");
}

void jump_not_parity_test()
{
    pc = 0;
    f = 0;
    set_parity_flag(false);

    set_byte_from_address((uint16_t) (pc + 1), (uint8_t) TEST_ADDRESS);
    set_byte_from_address((uint16_t) (pc + 2), 0);

    jump_condition(CONDITIONAL_PO);

    assert(pc == TEST_ADDRESS && "jump_not_parity_test failed!");
}

void jump_parity_test()
{
    pc = 0;
    f = 0;
    set_parity_flag(true);

    set_byte_from_address((uint16_t) (pc + 1), (uint8_t) TEST_ADDRESS);
    set_byte_from_address((uint16_t) (pc + 2), 0);

    jump_condition(CONDITIONAL_PE);

    assert(pc == TEST_ADDRESS && "jump_parity_test failed!");
}

void jump_not_sign_test()
{
    pc = 0;
    f = 0;
    set_sign_flag(false);

    set_byte_from_address((uint16_t) (pc + 1), (uint8_t) TEST_ADDRESS);
    set_byte_from_address((uint16_t) (pc + 2), 0);

    jump_condition(CONDITIONAL_P);

    assert(pc == TEST_ADDRESS && "jump_not_sign_test failed!");
}

void jump_sign_test()
{
    pc = 0;
    f = 0;
    set_sign_flag(true);

    set_byte_from_address((uint16_t) (pc + 1), (uint8_t) TEST_ADDRESS);
    set_byte_from_address((uint16_t) (pc + 2), 0);

    jump_condition(CONDITIONAL_M);

    assert(pc == TEST_ADDRESS && "jump_sign_test failed!");
}
