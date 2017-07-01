//
// Created by Jake Kinsella on 6/30/17.
//

#include "sub.h"

void sub_8bit(uint8_t *dst, const uint8_t src);
void handle_flags_sub(const int final_value, const int value1, const int value2);

void sub_register(const uint8_t src_register)
{
    printf("SUB r\n");

    int tmp = a;

    sub_8bit(&a, src_register);

    handle_flags_sub(a, tmp, src_register);
    pc++;
}

void sub_memory()
{
    printf("SUB M\n");

    int tmp = a;
    uint8_t byte = read_byte(h, l);

    sub_8bit(&a, byte);

    handle_flags_sub(a, tmp, byte);
    pc++;
}

void sub_immediate()
{
    printf("SUB data\n");

    int tmp = a;
    uint8_t byte = read_byte_from_address((uint16_t) (pc + 1));

    sub_8bit(&a, byte);

    handle_flags_sub(a, tmp, byte);
    pc += 2;
}

void sub_8bit(uint8_t *dst, const uint8_t src)
{
    if ((*dst - src) < 0) {
        *dst = 0;
        return;
    }

    *dst -= src;
}

void handle_flags_sub(const int final_value, const int value1, const int value2)
{
    handle_zero_flag(final_value);
    handle_sign_flag(final_value);
    handle_carry_flag_sub(value1, value2);
    handle_aux_carry_flag_sub(value1, value2);
    handle_parity_flag(a);
}
