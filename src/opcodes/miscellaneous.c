//
// Created by Jake Kinsella on 6/22/17.
//

#include "miscellaneous.h"

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

void nop()
{
    printf("NOP\n");

    pc++;
}
