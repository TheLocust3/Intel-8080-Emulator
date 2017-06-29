//
// Created by Jake Kinsella on 6/24/17.
//

#include "flags.h"

void handle_zero_flag(const int value)
{
    set_zero_flag(value == 0);
}

void handle_sign_flag(const int value)
{
    set_sign_flag((value & 0b10000000) > 0);
}

void handle_parity_flag(const int value)
{
    int tmp = value;
    int number_set_bits = 0;
    while (tmp > 0) {
        if ((tmp & 1) == 1) {
            number_set_bits++;
        }

        tmp = tmp >> 1;
    }

    set_parity_flag((number_set_bits % 2) == 0);
}

void handle_carry_flag_add(const int value1, const int value2)
{
    set_carry_flag((value1 + value2) > 0xFF);
}

void handle_carry_flag_sub(const int value1, const int value2)
{
    set_carry_flag((value1 - value2) < 0);
}

void handle_aux_carry_flag_add(const int value1, const int value2)
{
    set_aux_carry_flag(((value1 & 0xF) + (value2 & 0xF)) > 0xF);
}

void set_zero_flag(bool flag)
{
    if (flag) {
        f = (uint8_t) (f | (1 << 6));
        return;
    }

    f = (uint8_t) (f & ~(1 << 6));
}

int get_zero_flag()
{
    return (f & 0b01000000) >> 6;
}

bool is_zero_flag_set()
{
    return get_zero_flag() > 0;
}

void set_sign_flag(bool flag)
{
    if (flag) {
        f = (uint8_t) (f | (1 << 7));
        return;
    }

    f = (uint8_t) (f & ~(1 << 7));
}

int get_sign_flag()
{
    return (f & 0b10000000) >> 7;
}

bool is_sign_flag_set()
{
    return get_sign_flag() > 0;
}

void set_parity_flag(bool flag)
{
    if (flag) {
        f = (uint8_t) (f | (1 << 2));
        return;
    }

    f = (uint8_t) (f & ~(1 << 2));
}

int get_parity_flag()
{
    return (f & 0b00000100) >> 2;
}

bool is_parity_flag_set()
{
    return get_parity_flag() > 0;
}

void set_carry_flag(bool flag)
{
    if (flag) {
        f = (uint8_t) (f | (1 << 0));
        return;
    }

    f = (uint8_t) (f & ~(1 << 0));
}

int get_carry_flag()
{
    return (f & 0b00000001);
}

bool is_carry_flag_set()
{
    return get_carry_flag() > 0;
}

void set_aux_carry_flag(bool flag)
{
    if (flag) {
        f = (uint8_t) (f | (1 << 4));
        return;
    }

    f = (uint8_t) (f & ~(1 << 4));
}

int get_aux_carry_flag()
{
    return (f & 0b00010000) >> 4;
}

bool is_aux_carry_flag_set()
{
    return get_aux_carry_flag() > 0;
}
