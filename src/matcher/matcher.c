//
// Created by Jake Kinsella on 4/19/17.
//

#include <stdlib.h>
#include "matcher.h"
#include "instruction_template.h"

InstructionTemplate instruction_templates[255];
int instruction_template_pointer = 0;

bool match(uint8_t instruction)
{
    for (int i = 0; i < instruction_template_pointer; i++) {
        if (match_instruction_template(instruction, instruction_templates[i])) {
            return true;
        }
    }

    return false;
}

void add_instruction_template(InstructionTemplate instruction_template)
{
    instruction_templates[instruction_template_pointer] = instruction_template;
    instruction_template_pointer++;
}

bool match_instruction_template(uint8_t instruction, InstructionTemplate instruction_template)
{
    uint8_t binary_template = instruction_template.binary_template;

    int dst_code = get_dst_code_from_opcode(instruction);
    int src_code = get_src_code_from_opcode(instruction);
    int rp_code = get_rp_code_from_opcode(instruction);

    if (is_code_8bit_code(dst_code) && instruction_template.has_dst) {
        binary_template += dst_code << 3;
    }

    if (is_code_8bit_code(src_code) && instruction_template.has_src) {
        binary_template += src_code;
    }

    if (is_code_16bit_code(rp_code) && instruction_template.has_rp) {
        binary_template += rp_code << 4;
    }

    if (instruction == binary_template) {
        return true;
    }

    return false;
}

void run_instruction(int dst_code, int src_code, int rp_code, InstructionTemplate instruction_template)
{
    uint8_t dst_register = get_register_from_code(dst_code);
    uint8_t src_register = get_register_from_code(src_code);
    uint16_t rp_register = get_register_from_code(rp_code);

    // TODO: This is really gross
    if (instruction_template.has_dst && !instruction_template.has_src && !instruction_template.has_rp) {
        instruction_template.method(&dst_register);
    } else if (!instruction_template.has_dst && instruction_template.has_src && !instruction_template.has_rp) {
        instruction_template.method(&src_register);
    } else if (!instruction_template.has_dst && !instruction_template.has_src && instruction_template.has_rp) {
        instruction_template.method(&rp_register);
    } else if (instruction_template.has_dst && instruction_template.has_src && !instruction_template.has_rp) {
        instruction_template.method(&dst_register, &src_register);
    } else if (!instruction_template.has_dst && !instruction_template.has_src && !instruction_template.has_rp) {
        instruction_template.method();
    } else {
        printf("Instruction arguments not matched!\n");
        exit(1);
    }
}
