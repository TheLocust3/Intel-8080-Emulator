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
    printf("%d: %d\n", pc, instruction);

    // pc starts at instruction when passed to handle functions

    int index = match(instruction);
    if (index != -1) {
        InstructionTemplate template = get_registered_template(index);
    }
}

void print_register_status()
{
    printf("A: %d, B: %d, C: %d, D: %d, E: %d, F: %d, H: %d, L: %d, SP: %d\n", a, b, c, d, e, f, h, l, combine_bytes(s, p));
}