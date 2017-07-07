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

#endif //INC_8080_EMULATOR_BITWISE_H
