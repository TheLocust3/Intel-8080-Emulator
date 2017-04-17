//
// Created by Jake Kinsella on 4/17/17.
//

#include "move.h"
#include "../registers.h"
#include "../ram.h"

void move_byte(uint8_t *dst, const uint8_t src);
void move_byte_to_memory(const uint8_t dst_address, const uint8_t src);

void move_register(uint8_t *dst_register, uint8_t *src_register)
{
    move_byte(dst_register, *src_register);
    pc++;
}

void move_from_memory(uint8_t *dst_register)
{
    move_byte(dst_register, read_byte(h, l));
    pc++;
}

void move_to_memory(const uint8_t src_register)
{
    move_byte_to_memory(read_byte(h, l), src_register);
    pc++;
}

void move_byte(uint8_t *dst, const uint8_t src)
{
    *dst = src;
}

void move_byte_to_memory(const uint8_t dst_address, const uint8_t src)
{
    set_byte_from_address(dst_address, src);
}