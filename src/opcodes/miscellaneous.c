//
// Created by Jake Kinsella on 6/22/17.
//

#include "miscellaneous.h"
#include "../pins/data_bus.h"

// TODO: Not currently correct
void input()
{
    printf("IN port\n");

    a = read_data_bus();
    pc++;
}

void output()
{
    printf("OUT port\n");

    write_data_bus(a);
    pc++;
}

void enable_interrupts()
{
    printf("EI\n");

    interrupts_enabled = true;
    pc++;
}

void disable_interrupts()
{
    printf("DI\n");

    interrupts_enabled = false;
    pc++;
}

void halt()
{
    printf("HLT\n");

    running = false;
    pc++;
}

void nop()
{
    printf("NOP\n");
    pc++;
}
