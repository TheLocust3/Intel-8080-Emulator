//
// Created by Jake Kinsella on 6/25/17.
//

#include "add.h"

void handle_flags(const int final_value, const int value1, const int value2);

void add_8bit(uint8_t *dst, const uint8_t src);

void add_register(const uint8_t src_register)
{
    printf("ADD r\n");

    int tmp = a;

    add_8bit(&a, src_register);

    handle_flags(a, tmp, src_register);
}

void add_memory()
{
    printf("ADD (HL)\n");

    int tmp = a;
    int byte = read_byte(h, l);

    add_8bit(&a, (const uint8_t) byte);

    handle_flags(a, tmp, byte);
}

void add_8bit(uint8_t *dst, const uint8_t src)
{
    if ((*dst + src) > 0xFF) {
        *dst = 0xFF;
        return;
    }

    *dst += src;
}

void handle_flags(const int final_value, const int value1, const int value2)
{
    handle_zero_flag(final_value);
    handle_sign_flag(final_value);
    handle_carry_flag_add(value1, value2);
    handle_aux_carry_flag_add(value1, value2);
    handle_parity_flag(a);
}
