//
// Created by Jake Kinsella on 4/19/17.
//

#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include "instruction_template.h"

InstructionTemplate setup_binary_template(InstructionTemplate *instruction_template);

char * strip_nonbinary(char *string);
int binary_string_to_int(char *string);

bool has_rp(InstructionTemplate instruction_template);
bool has_dst(InstructionTemplate instruction_template);
bool has_src(InstructionTemplate instruction_template);

InstructionTemplate new_instruction_template(char *template)
{
    assert(strlen(template) == 8);

    InstructionTemplate instruction_template;
    instruction_template.raw_template = template;

    instruction_template = setup_binary_template(&instruction_template);
    instruction_template.has_rp = has_rp(instruction_template);
    instruction_template.has_dst = has_dst(instruction_template);
    instruction_template.has_src = has_src(instruction_template);

    return instruction_template;
}

InstructionTemplate setup_binary_template(InstructionTemplate *instruction_template)
{
    char *binary_string = strip_nonbinary((*instruction_template).raw_template);
    int binary = binary_string_to_int(binary_string);
    (*instruction_template).binary_template = (uint8_t) binary;

    return *instruction_template;
}

char * strip_nonbinary(char *string)
{
    char *tmp_string = malloc(sizeof(char *) * 8);
    strcpy(tmp_string, string);

    for (int i = 0; i < strlen(tmp_string); i++) {
        if (tmp_string[i] != '0' && tmp_string[i] != '1') {
            tmp_string[i] = '0';
        }
    }

    return tmp_string;
}

int binary_string_to_int(char *string)
{
    int number = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == '1') {
            number += pow(2, 8 - i);
        }
    }

    return number;
}

// --RP----
bool has_rp(InstructionTemplate instruction_template)
{
    return instruction_template.raw_template[2] == 'R' && instruction_template.raw_template[3] == 'P';
}

// --DDD---
bool has_dst(InstructionTemplate instruction_template)
{
    return instruction_template.raw_template[2] == 'D' && instruction_template.raw_template[3] == 'D' && instruction_template.raw_template[4] == 'D';
}

// -----SSS
bool has_src(InstructionTemplate instruction_template)
{
    return instruction_template.raw_template[5] == 'S' && instruction_template.raw_template[6] == 'S' && instruction_template.raw_template[7] == 'S';
}
