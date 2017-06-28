//
// Created by Jake Kinsella on 6/25/17.
//

#include "add.h"

void add_8bit(uint8_t *dst, const uint8_t src);

void add_register(const uint8_t src_register)
{
    printf("ADD r\n");

    int tmp = a;

    add_8bit(&a, src_register);

    handle_zero_flag(a);
    handle_sign_flag(a);
    handle_carry_flag_add(tmp, src_register);
    handle_aux_carry_flag_add(tmp, src_register);
    handle_parity_flag(a);
}

void add_memory()
{
    printf("ADD (HL)\n");

    int tmp = a;
    int byte = read_byte(h, l);

    add_8bit(&a, byte);

    handle_zero_flag(a);
    handle_sign_flag(a);
    handle_carry_flag_add(tmp, byte);
    handle_aux_carry_flag_add(tmp, byte);
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
