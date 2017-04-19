//
// Created by Jake Kinsella on 4/17/17.
//

#include "data_transfer.h"
#include "../registers.h"
#include "../ram.h"
#include "../common_functions.h"


void move_byte(uint8_t *dst, const uint8_t src);
void move_16bit(uint16_t *dst, const uint16_t src);
void move_byte_to_memory(const uint16_t dst_address, const uint8_t src);

// MOV

void move_register(uint8_t *dst_register, const uint8_t src_register)
{
    printf("MOV r1, r2\n");

    move_byte(dst_register, src_register);
    pc++;
}

void move_from_memory(uint8_t *dst_register)
{
    printf("MOV r, M\n");

    move_byte(dst_register, read_byte(h, l));
    pc++;
}

void move_to_memory(const uint8_t src_register)
{
    printf("MOV M, r\n");

    move_byte_to_memory(combine_bytes(h, l), src_register);
    pc++;
}

// MVI

void move_immediate(uint8_t *dst_register)
{
    printf("MVI r, data\n");

    move_byte(dst_register, read_byte_from_address((uint16_t) (pc + 1)));
    pc += 2;
}

void move_to_memory_immediate()
{
    printf("MVI M, data\n");

    move_byte_to_memory(combine_bytes(h, l), read_byte_from_address((uint16_t) (pc + 1)));
    pc += 2;
}

// Misc

void load_register_pair_immediate(uint16_t *dst_register_pair)
{
    printf("LXI rp, data 16\n");

    uint16_t data = combine_bytes(read_byte_from_address((uint16_t) (pc + 2)), read_byte_from_address((uint16_t) (pc + 1)));
    move_16bit(dst_register_pair, data);
    pc += 3;
}

void load_accumulator_direct()
{
    printf("LDA addr\n");

    uint16_t address = combine_bytes(read_byte_from_address((uint16_t) (pc + 2)), read_byte_from_address((uint16_t) (pc + 1)));
    move_byte(&a, read_byte_from_address(address));
    pc += 3;
}

void move_byte(uint8_t *dst, const uint8_t src)
{
    *dst = src;
}

void move_16bit(uint16_t *dst, const uint16_t src)
{
    *dst = src;
}

void move_byte_to_memory(const uint16_t dst_address, const uint8_t src)
{
    set_byte_from_address(dst_address, src);
}
