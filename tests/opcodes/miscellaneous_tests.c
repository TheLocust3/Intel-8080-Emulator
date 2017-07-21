//
// Created by Jake Kinsella on 6/22/17.
//

#include <assert.h>
#include "../../src/opcodes/miscellaneous.h"

void enable_interrupts_test();
void nop_test();

int main(int argc, const char* argv[])
{
    enable_interrupts_test();
    nop_test();

    return 0;
}

void enable_interrupts_test()
{
    enable_interrupts();

    assert(interrupts_enabled == true && "enable_interrupts_test failed!");
}

void nop_test()
{
    pc = 0;
    nop();

    assert(pc == 1 && "nop_test failed!");
}