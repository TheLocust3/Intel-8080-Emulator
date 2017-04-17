//
// Created by Jake Kinsella on 4/17/17.
//

#ifndef INC_8080_EMULATOR_REGISTERS_C_H
#define INC_8080_EMULATOR_REGISTERS_C_H

#include <stdint.h>

uint16_t pc, sp;
uint8_t a, b, c, d, f, h, l;

void initialize_registers();

#endif //INC_8080_EMULATOR_REGISTERS_C_H
