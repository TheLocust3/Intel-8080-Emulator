//
// Created by Jake Kinsella on 4/17/17.
//

#include "data_transfer.h"
#include "../registers.h"
#include "../ram.h"
#include "../common_functions.h"


void move_byte(uint8_t *dst, const uint8_t src);
void move_register_pair(RegisterPair *dst_register_pair, const uint16_t src);
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

void load_register_pair_immediate(RegisterPair *dst_register_pair)
{
    printf("LXI rp, data 16\n");


    uint16_t data = read_16bits_from_address((uint16_t) (pc + 1));
    move_register_pair(dst_register_pair, data);
    pc += 3;
}

void load_accumulator_direct()
{
    printf("LDA addr\n");

    uint16_t address = read_16bits_from_address((uint16_t) (pc + 1));
    move_byte(&a, read_byte_from_address(address));
    pc += 3;
}

void store_accumulator_direct()
{
    printf("STA addr\n");

    uint16_t address = read_16bits_from_address((uint16_t) (pc + 1));

    set_byte_from_address(address, a);
    pc += 3;
}

void load_HL_direct()
{
    printf("LHLD addr\n");

    uint16_t address = read_16bits_from_address((uint16_t) (pc + 1));

    l = read_byte_from_address(address);
    h = read_byte_from_address((uint16_t) (address + 1));
    pc += 3;
}

void store_HL_direct()
{
    printf("SHLD addr\n");

    uint16_t address = read_16bits_from_address((uint16_t) (pc + 1));

    set_byte_from_address(address, l);
    set_byte_from_address((uint16_t) (address + 1), h);
    pc += 3;
}

void load_accumulator_indirect(const RegisterPair src_register_pair)
{
    printf("LDAX rp\n");

    a = read_byte_from_address(combine_bytes(*src_register_pair.high, *src_register_pair.low));
    pc += 1;
}

void store_accumulator_indirect(const RegisterPair dst_register_pair)
{
    printf("STAX rp\n");

    set_byte(*dst_register_pair.high, *dst_register_pair.low, a);

    pc += 1;
}

void exchange_HL_DE()
{
    printf("XCHG\n");

    uint8_t d_tmp = d;
    uint8_t e_tmp = e;

    d = h;
    e = l;

    h = d_tmp;
    l = e_tmp;

    pc += 1;
}

void move_byte(uint8_t *dst, const uint8_t src)
{
    *dst = src;
}

void move_register_pair(RegisterPair *dst_register_pair, const uint16_t src)
{
    *dst_register_pair->high = get_high_order_byte(src);
    *dst_register_pair->low = get_low_order_byte(src);
}

void move_byte_to_memory(const uint16_t dst_address, const uint8_t src)
{
    set_byte_from_address(dst_address, src);
}
