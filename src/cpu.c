//
// Created by Jake Kinsella on 4/17/17.
//

#include "cpu.h"
#include "registers.h"
#include "ram.h"
#include "matcher/matcher.h"

void initialize()
{
    initialize_registers();
    initialize_ram();
}

void cycle()
{
    uint8_t instruction = read_byte_from_address(pc);
    printf("0x%x: 0x%x\n", pc, instruction);

    // pc starts at instruction when passed to handle functions

    int index = match(instruction);
    if (index != -1) {
        InstructionTemplate template = get_registered_template(index);

        int dst_code = get_dst_code_from_opcode(instruction);
        int src_code = get_src_code_from_opcode(instruction);
        int rp_code = get_rp_code_from_opcode(instruction);
        int condition_code = get_condition_code_from_opcode(instruction);
        run_instruction(dst_code, src_code, rp_code, condition_code, template);
    }
}

void print_register_status()
{
    printf("A: 0x%x, B: 0x%x, C: 0x%x, D: 0x%x, E: 0x%x, F: 0x%x, H: 0x%x, L: 0x%x, SP: 0x%x\n", a, b, c, d, e, f, h, l, combine_bytes(s, p));
}