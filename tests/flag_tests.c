//
// Created by Jake Kinsella on 6/27/17.
//

#include <assert.h>
#include "../src/flags.h"

void zero_flag_test();
void sign_flag_test();
void parity_flag_test();
void carry_flag_add_test();
void carry_flag_sub_test();
void aux_carry_flag_add_test();
void aux_carry_flag_sub_test();

int main(int argc, const char* argv[])
{
    zero_flag_test();
    sign_flag_test();
    parity_flag_test();
    carry_flag_add_test();
    carry_flag_sub_test();
    aux_carry_flag_add_test();
    aux_carry_flag_sub_test();

    return 0;
}

void zero_flag_test()
{
    f = 0;

    handle_zero_flag(0);
    assert(is_zero_flag_set() && "zero_flag_test failed!");

    handle_zero_flag(10);
    assert(!is_zero_flag_set() && "zero_flag_test failed!");
}

void sign_flag_test()
{
    f = 0;

    handle_sign_flag(0b10000000);
    assert(is_sign_flag_set() && "sign_flag_test failed!");

    handle_sign_flag(0);
    assert(!is_sign_flag_set() && "sign_flag_test failed!");
}

void parity_flag_test()
{
    f = 0;

    handle_parity_flag(0b10101010);
    assert(is_parity_flag_set() && "parity_flag_test failed!");

    handle_parity_flag(0b10101011);
    assert(!is_parity_flag_set() && "parity_flag_test failed!");
}

void carry_flag_add_test()
{
    f = 0;

    handle_carry_flag_add(0b10000000, 0b10000000);
    assert(is_carry_flag_set() && "carry_flag_add_test failed!");

    handle_carry_flag_add(0, 0);
    assert(!is_carry_flag_set() && "carry_flag_add_test failed!");
}

void carry_flag_sub_test()
{
    f = 0;

    handle_carry_flag_sub(0b10000000, 0b10000001);
    assert(is_carry_flag_set() && "carry_flag_sub_test failed!");

    handle_carry_flag_sub(0, 0);
    assert(!is_carry_flag_set() && "carry_flag_sub_test failed!");
}

void aux_carry_flag_add_test()
{
    f = 0;

    handle_aux_carry_flag_add(0b00001000, 0b00001000);
    assert(is_aux_carry_flag_set() && "aux_carry_flag_add_test failed!");

    handle_aux_carry_flag_add(0, 0);
    assert(!is_aux_carry_flag_set() && "aux_carry_flag_add_test failed!");
}

void aux_carry_flag_sub_test()
{
    f = 0;

    handle_aux_carry_flag_sub(0b00000100, 0b00001000);
    assert(is_aux_carry_flag_set() && "aux_carry_flag_sub_test failed!");

    handle_aux_carry_flag_sub(0xF, 0xF);
    assert(!is_aux_carry_flag_set() && "aux_carry_flag_sub_test failed!");
}
