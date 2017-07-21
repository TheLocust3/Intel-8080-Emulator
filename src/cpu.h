//
// Created by Jake Kinsella on 4/17/17.
//

#ifndef INC_8080_EMULATOR_CPU_H
#define INC_8080_EMULATOR_CPU_H

#include <stdio.h>
#include <stdbool.h>

bool interrupts_enabled;

void initialize();
void cycle();
void print_register_status();

#endif //INC_8080_EMULATOR_CPU_H
