//
// Created by Jake Kinsella on 4/19/17.
//

#ifndef INC_8080_EMULATOR_MATCHER_H
#define INC_8080_EMULATOR_MATCHER_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../common_functions.h"
#include "../registers.h"
#include "instruction_template.h"

int match(uint8_t instruction);
void add_instruction_template(InstructionTemplate instruction_template);
void clear_all_registered_templates();
InstructionTemplate * get_all_registered_templates();
InstructionTemplate get_registered_template(int index);
bool match_instruction_template(uint8_t instruction, InstructionTemplate instruction_template);
void run_instruction(int dst_code, int src_code, int rp_code, InstructionTemplate instruction_template);

#endif //INC_8080_EMULATOR_MATCHER_H
