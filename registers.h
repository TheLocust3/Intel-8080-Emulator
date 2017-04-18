//
// Created by Jake Kinsella on 4/17/17.
//

#ifndef INC_8080_EMULATOR_REGISTERS_C_H
#define INC_8080_EMULATOR_REGISTERS_C_H

#include <stdio.h>
#include <stdint.h>

#define NULL_REGISTER UINT64_MAX

#define A_CODE 0b111
#define B_CODE 0b000
#define C_CODE 0b001
#define D_CODE 0b010
#define E_CODE 0b011
#define H_CODE 0b100
#define L_CODE 0b101

uint16_t pc, sp;
uint8_t a, b, c, d, e, f, h, l;

void initialize_registers();
uint8_t get_register_from_code(int code);

#endif //INC_8080_EMULATOR_REGISTERS_C_H
