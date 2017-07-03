//
// Created by Jake Kinsella on 7/2/17.
//

#ifndef INC_8080_EMULATOR_INCREMENT_H
#define INC_8080_EMULATOR_INCREMENT_H

#include <stdint.h>
#include <stdio.h>
#include "../../registers.h"
#include "../../flags.h"
#include "../../ram.h"
#include "../../common_functions.h"

void increment_register(uint8_t *dst);
void increment_memory();
void decrement_register(uint8_t *dst);
void decrement_memory();
void increment_register_pair(const RegisterPair dst_register_pair);
void decrement_register_pair(const RegisterPair dst_register_pair);

#endif //INC_8080_EMULATOR_INCREMENT_H
