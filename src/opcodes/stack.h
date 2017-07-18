//
// Created by Jake Kinsella on 7/14/17.
//

#ifndef INC_8080_EMULATOR_STACK_H
#define INC_8080_EMULATOR_STACK_H

#include "../registers.h"
#include "../ram.h"
#include "../common_functions.h"
#include "../registers.h"

void push(uint8_t value);
uint8_t pop();

void push_register_pair(RegisterPair *dst_register_pair);
void push_processor_status_word();
void pop_register_pair(RegisterPair *dst_register_pair);
void pop_processor_status_word();
void exchange_stack_top_with_HL();
void move_HL_to_SP();

#endif //INC_8080_EMULATOR_STACK_H
