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
    pc++;
}

void add_memory()
{
    printf("ADD (HL)\n");

    int tmp = a;
    uint8_t byte = read_byte(h, l);

    add_8bit(&a, byte);

    handle_flags(a, tmp, byte);
    pc++;
}

void add_immediate()
{
    printf("ADI data\n");

    int tmp = a;
    uint8_t byte = read_byte_from_address((uint16_t) (pc + 1));

    add_8bit(&a, byte);

    handle_flags(a, tmp, byte);
    pc += 2;
}

void add_register_with_carry(const uint8_t src_register)
{
    printf("ADC r\n");

    int tmp = a;
    uint8_t byte = (uint8_t) (src_register + get_carry_flag());

    add_8bit(&a, byte);

    handle_flags(a, tmp, byte);
    pc++;
}

void add_memory_with_carry()
{
    printf("ADC M\n");

    int tmp = a;
    uint8_t byte = (uint8_t) (read_byte(h, l) + get_carry_flag());

    add_8bit(&a, byte);

    handle_flags(a, tmp, byte);
    pc++;
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
