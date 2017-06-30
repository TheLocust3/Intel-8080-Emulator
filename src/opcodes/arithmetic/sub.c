//
// Created by Jake Kinsella on 6/30/17.
//

#include "sub.h"

void sub_8bit(uint8_t *dst, const uint8_t src);
void handle_flags(const int final_value, const int value1, const int value2);

void sub_register(const uint8_t src_register)
{
    printf("SUB r\n");

    int tmp = a;

    sub_8bit(&a, src_register);

    handle_flags(a, tmp, src_register);
    pc++;
}

void sub_8bit(uint8_t *dst, const uint8_t src)
{
    if ((*dst - src) < 0) {
        *dst = 0;
        return;
    }

    *dst -= src;
}

void handle_flags(const int final_value, const int value1, const int value2)
{
    handle_zero_flag(final_value);
    handle_sign_flag(final_value);
    handle_carry_flag_sub(value1, value2);
    handle_aux_carry_flag_sub(value1, value2);
    handle_parity_flag(a);
}
