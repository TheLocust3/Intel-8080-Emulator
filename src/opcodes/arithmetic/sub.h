//
// Created by Jake Kinsella on 6/30/17.
//

#ifndef INC_8080_EMULATOR_SUB_H
#define INC_8080_EMULATOR_SUB_H

#include <stdint.h>
#include <stdio.h>
#include "../../registers.h"
#include "../../flags.h"
#include "../../ram.h"

void sub_register(const uint8_t src_register);
void sub_memory();
void sub_immediate();

#endif //INC_8080_EMULATOR_SUB_H
