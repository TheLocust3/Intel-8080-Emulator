//
// Created by Jake Kinsella on 6/22/17.
//

#include "miscellaneous.h"
#include "../data_bus.h"

// TODO: Not currently correct
void input()
{
    printf("IN port\n");

    a = read_bus();
}

void output()
{
    printf("OUT port\n");

    write_bus(a);
}

void enable_interrupts()
{
    printf("EI\n");

    interrupts_enabled = true;
}

void disable_interrupts()
{
    printf("DI\n");

    interrupts_enabled = false;
}

void halt()
{
    printf("HLT\n");

    running = false;
}

void nop()
{
    printf("NOP\n");

    pc++;
}
