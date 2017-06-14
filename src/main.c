//
// Created by Jake Kinsella on 4/16/17.
//

#include <stdio.h>

#include "cpu.h"
#include "ram.h"
#include "opcodes/data_transfer.h"
#include "matcher/instruction_template.h"
#include "matcher/matcher.h"

void setup_opcodes();

int main(int argc, const char* argv[])
{
    setup_opcodes();
    initialize();

    for (int i = 0; i < 10; i++) {
        cycle();
        print_register_status();
    }

    return 0;
}

void setup_opcodes()
{
    InstructionTemplate move_register_template = new_instruction_template("01DDDSSS", &move_register);
    add_instruction_template(move_register_template);

    InstructionTemplate move_from_memory_template = new_instruction_template("01DDD110", &move_from_memory);
    add_instruction_template(move_from_memory_template);

    InstructionTemplate move_to_memory_template = new_instruction_template("01110SSS", &move_to_memory);
    add_instruction_template(move_to_memory_template);

    InstructionTemplate move_immediate_template = new_instruction_template("00DDD110", &move_immediate);
    add_instruction_template(move_immediate_template);

    InstructionTemplate move_to_memory_immediate_template = new_instruction_template("00110110", &move_to_memory_immediate);
    add_instruction_template(move_to_memory_immediate_template);

    InstructionTemplate load_register_pair_immediate_template = new_instruction_template("00RR0001", &load_register_pair_immediate);
    add_instruction_template(load_register_pair_immediate_template);

    InstructionTemplate load_accumulator_direct_template = new_instruction_template("00111010", &load_accumulator_direct);
    add_instruction_template(load_accumulator_direct_template);
}
