//
// Created by Jake Kinsella on 4/17/17.
//

#include "cpu.h"
#include "registers.h"
#include "ram.h"
#include "matcher/matcher.h"
#include "pins/pins.h"
#include "opcodes/branch/miscellaneous_branch.h"
#include "log.h"

void handle_interrupt();

void initialize()
{
    running = true;
    interrupts_enabled = true;

    initialize_pins();
    initialize_registers();
    initialize_ram();
}

void cycle()
{
    handle_input_pins();

    if (!running) return;

    uint8_t instruction = read_byte_from_address(pc);
    log("0x%x: 0x%x\n", pc, instruction);

    int index = match(instruction);
    if (index != -1) {
        InstructionTemplate template = get_registered_template(index);

        int dst_code = get_dst_code_from_opcode(instruction);
        int src_code = get_src_code_from_opcode(instruction);
        int rp_code = get_rp_code_from_opcode(instruction);
        int condition_code = get_condition_code_from_opcode(instruction);
        run_instruction(dst_code, src_code, rp_code, condition_code, template);
    }

    handle_interrupt();
}

void handle_interrupt()
{
    if (pins[INT]) {
        int location = 0;
        location = set_bit((uint8_t) location, 0, pins[A0]);
        location = set_bit((uint8_t) location, 1, pins[A1]);
        location = set_bit((uint8_t) location, 2, pins[A1]);

        restart(location);
        uint8_t instruction = (uint8_t) ((0b11 << 6) + (location << 3) + 111);
        write_data_bus(instruction);
    }
}

void print_register_status()
{
    log("A: 0x%x, B: 0x%x, C: 0x%x, D: 0x%x, E: 0x%x, F: 0x%x, H: 0x%x, L: 0x%x, SP: 0x%x\n", a, b, c, d, e, f, h, l, combine_bytes(s, p));
}