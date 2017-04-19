//
// Created by Jake Kinsella on 4/19/17.
//

#ifndef INC_8080_EMULATOR_INSTRUCTION_TEMPLATE_H
#define INC_8080_EMULATOR_INSTRUCTION_TEMPLATE_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    char *raw_template;
    uint8_t binary_template;
    bool has_rp;
    bool has_dst;
    bool has_src;
} InstructionTemplate;

InstructionTemplate new_instruction_template(char *template);

#endif //INC_8080_EMULATOR_INSTRUCTION_TEMPLATE_H
