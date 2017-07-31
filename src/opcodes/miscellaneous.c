//
// Created by Jake Kinsella on 6/22/17.
//

#include "miscellaneous.h"
#include "../pins/data_bus.h"
#include "../ram.h"
#include "../pins/address_bus.h"
#include "../log.h"

void input()
{
    log("IN port\n");

    uint8_t byte = read_byte_from_address((uint16_t) (pc + 1));

    a = read_data_bus();
    write_address_bus((byte << 8) + byte);

    pc += 2;
}

void output()
{
    log("OUT port\n");

    uint8_t byte = read_byte_from_address((uint16_t) (pc + 1));

    write_data_bus(a);
    write_address_bus((byte << 8) + byte);

    pc += 2;
}

void enable_interrupts()
{
    log("EI\n");

    interrupts_enabled = true;
    pc++;
}

void disable_interrupts()
{
    log("DI\n");

    interrupts_enabled = false;
    pc++;
}

void halt()
{
    log("HLT\n");

    running = false;
    pc++;
}

void nop()
{
    log("NOP\n");
    pc++;
}
