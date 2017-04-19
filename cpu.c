//
// Created by Jake Kinsella on 4/17/17.
//

#include "cpu.h"
#include "registers.h"
#include "ram.h"

#include "handlers/data_transfer_handler.h"

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

    handle_data_transfer_instruction(instruction);
}