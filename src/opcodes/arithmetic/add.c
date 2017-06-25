//
// Created by Jake Kinsella on 6/25/17.
//

#include "add.h"

void add_8bit(uint8_t *dst, const uint8_t src);

void add_register(const uint8_t src_register)
{
    printf("ADD r\n");

    add_8bit(&a, src_register);

    handle_zero_flag(a);
    handle_sign_flag(a);
    handle_carry_flag_add(a, src_register);
    // TODO handle aux carry flag
    handle_parity_flag(a);
}

void add_8bit(uint8_t *dst, const uint8_t src)
{
    if ((*dst + src) > 0xFF) {
        *dst = 0xFF;
        return;
    }

    *dst += src;
}
