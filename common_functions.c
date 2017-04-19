//
// Created by Jake Kinsella on 4/17/17.
//

#include "common_functions.h"

uint16_t combine_bytes(uint8_t high, uint8_t low)
{
    return (high << 8) + low;
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