//
// Created by Jake Kinsella on 4/17/17.
//

#ifndef INC_8080_EMULATOR_MOVE_H
#define INC_8080_EMULATOR_MOVE_H

#include <stdio.h>
#include <stdint.h>
#include "../registers.h"

void move_register(uint8_t *dst_register, const uint8_t src_register);
void move_from_memory(uint8_t *dst_register);
void move_to_memory(const uint8_t src_register);

void move_immediate(uint8_t *dst_register);
void move_to_memory_immediate();

void load_register_pair_immediate(RegisterPair *dst_register_pair);
void load_accumulator_direct();
void store_accumulator_direct();
void load_HL_direct();
void store_HL_direct();
void load_accumulator_indirect(const RegisterPair src_register_pair);
void store_accumulator_indirect(const RegisterPair dst_register_pair);

#endif //INC_8080_EMULATOR_MOVE_H
