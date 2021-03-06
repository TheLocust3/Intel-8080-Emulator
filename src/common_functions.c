//
// Created by Jake Kinsella on 4/17/17.
//

#include "common_functions.h"

int get_bit(uint8_t byte, int bit_number)
{
    return (byte & (1 << bit_number)) >> bit_number;
}

int get_bit_16bit(uint16_t byte, int bit_number)
{
    return (byte & (1 << bit_number)) >> bit_number;
}

uint8_t set_bit(uint8_t byte, int bit_number, bool set)
{
    if (set) {
        return (uint8_t) (byte | (1 << bit_number));
    }

    return (uint8_t) (byte & ~(1 << bit_number));
}

uint16_t set_bit_16bit(uint16_t value, int bit_number, bool set)
{
    if (set) {
        return (uint16_t) (value | (1 << bit_number));
    }

    return (uint16_t) (value & ~(1 << bit_number));
}

uint16_t combine_bytes(uint8_t high, uint8_t low)
{
    return (high << 8) + low;
}

uint8_t get_high_order_byte(uint16_t number)
{
    return (uint8_t) ((number & 0xFF00) >> 8);
}

uint8_t get_low_order_byte(uint16_t number)
{
    return (uint8_t) (number & 0x00FF);
}

int get_dst_code_from_opcode(int instruction)
{
    return (instruction & 0b00111000) >> 3;
}

int get_src_code_from_opcode(int instruction)
{
    return (instruction & 0b00000111);
}

int get_rp_code_from_opcode(int instruction)
{
    return (instruction & 0b00110000) >> 6;
}

int get_condition_code_from_opcode(int instruction)
{
    return (instruction & 0b00111000) >> 3;
}