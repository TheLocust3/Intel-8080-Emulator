//
// Created by Jake Kinsella on 6/22/17.
//

#ifndef INC_8080_EMULATOR_MISCELLANEOUS_H
#define INC_8080_EMULATOR_MISCELLANEOUS_H

#include "../registers.h"
#include "../cpu.h"

void enable_interrupts();
void disable_interrupts();
void nop();

#endif //INC_8080_EMULATOR_MISCELLANEOUS_H
