//
// Created by Jake Kinsella on 6/24/17.
//

#include "flags.h"

void set_zero_flag(bool flag)
{
    if (flag) {
        f = (uint8_t) (f | (1 << 6));
        return;
    }

    f = (uint8_t) (f | ~(1 << 6));
}

void set_sign_flag(bool flag)
{
    if (flag) {
        f = (uint8_t) (f | (1 << 7));
        return;
    }

    f = (uint8_t) (f | ~(1 << 7));
}

void set_parity_flag(bool flag)
{
    if (flag) {
        f = (uint8_t) (f | (1 << 2));
        return;
    }

    f = (uint8_t) (f | ~(1 << 2));
}

void set_carry_flag(bool flag)
{
    if (flag) {
        f = (uint8_t) (f | (1 << 0));
        return;
    }

    f = (uint8_t) (f | ~(1 << 0));
}

void set_aux_carry_flag(bool flag)
{
    if (flag) {
        f = (uint8_t) (f | (1 << 4));
        return;
    }

    f = (uint8_t) (f | ~(1 << 4));
}
