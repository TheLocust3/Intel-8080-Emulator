//
// Created by Jake Kinsella on 6/25/17.
//

#ifndef INC_8080_EMULATOR_ADD_H
#define INC_8080_EMULATOR_ADD_H

#include <stdint.h>
#include "../../registers.h"
#include "../../flags.h"
#include "../../ram.h"

void add_register(const uint8_t src_register);
void add_memory();
void add_immediate();
void add_register_with_carry(const uint8_t src_register);
void add_memory_with_carry();

#endif //INC_8080_EMULATOR_ADD_H
