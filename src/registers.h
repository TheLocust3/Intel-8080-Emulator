//
// Created by Jake Kinsella on 4/17/17.
//

#ifndef INC_8080_EMULATOR_REGISTERS_C_H
#define INC_8080_EMULATOR_REGISTERS_C_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define NULL_REGISTER UINT32_MAX

#define A_CODE 0b111
#define B_CODE 0b000
#define C_CODE 0b001
#define D_CODE 0b010
#define E_CODE 0b011
#define H_CODE 0b100
#define L_CODE 0b101

#define BC_CODE 00
#define DE_CODE 01
#define HL_CODE 10
#define SP_CODE 11

typedef struct {
    uint8_t *high;
    uint8_t *low;
} RegisterPair;

uint16_t pc;
uint8_t a, b, c, d, e, f, h, l, s, p;

void initialize_registers();
bool is_code_8bit_code(int code);
uint8_t get_register_from_code(int code);
bool is_code_16bit_code(int code);
RegisterPair get_register_pair_from_code(int code);
bool does_register_pair_equal(RegisterPair register_pair, uint16_t value);
RegisterPair create_register_pair(uint8_t *high, uint8_t *low);

#endif //INC_8080_EMULATOR_REGISTERS_C_H
