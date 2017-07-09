//
// Created by Jake Kinsella on 7/5/17.
//

#ifndef INC_8080_EMULATOR_BITWISE_H
#define INC_8080_EMULATOR_BITWISE_H

#include <stdint.h>
#include "../../registers.h"
#include "../../flags.h"

void and_register(const uint8_t src_register);
void and_memory();
void and_immediate();

void exclusive_or_register(const uint8_t src_register);
void exclusive_or_memory();
void exclusive_or_immediate();

void or_register(const uint8_t src_register);
void or_memory();
void or_immediate();

void rotate_left();
void rotate_right();
void rotate_left_through_carry();

#endif //INC_8080_EMULATOR_BITWISE_H
