//
// Created by Jake Kinsella on 7/8/17.
//

#ifndef INC_8080_EMULATOR_MISCELLANEOUS_LOGICAL_H
#define INC_8080_EMULATOR_MISCELLANEOUS_LOGICAL_H

#include <stdio.h>
#include "../../registers.h"
#include "../../flags.h"

void compare_register(const uint8_t src_register);
void compare_memory();

#endif //INC_8080_EMULATOR_MISCELLANEOUS_LOGICAL_H
