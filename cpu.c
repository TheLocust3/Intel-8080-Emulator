//
// Created by Jake Kinsella on 4/17/17.
//

#include "cpu.h"
#include "registers.h"
#include "ram.h"

#include "opcodes/move.h"

void initialize()
{
    initialize_registers();
    initialize_ram();
}

void cycle()
{
    uint8_t instruction = read_byte_from_address(pc);
    printf("%d: %d\n", pc, instruction);

    handle_move_instruction(instruction);
}