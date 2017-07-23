//
// Created by Jake Kinsella on 6/22/17.
//

#include <assert.h>
#include "../../src/opcodes/miscellaneous.h"
#include "../../src/data_bus.h"

void input_test();
void output_test();
void enable_interrupts_test();
void disable_interrupts_test();
void halt_test();
void nop_test();

const int TEST_VALUE = 10;

int main(int argc, const char* argv[])
{
    input_test();
    enable_interrupts_test();
    disable_interrupts_test();
    halt_test();
    nop_test();

    return 0;
}

void input_test()
{
    a = 0;
    write_bus(TEST_VALUE);

    input();

    assert(a == TEST_VALUE && "input_test failed!");
}

void output_test()
{
    a = TEST_VALUE;
    write_bus(0);

    output();

    assert(read_bus() == TEST_VALUE && "output_test failed!");
}

void enable_interrupts_test()
{
    running = false;

    enable_interrupts();

    assert(interrupts_enabled == true && "enable_interrupts_test failed!");
}

void disable_interrupts_test()
{
    running = true;

    disable_interrupts();

    assert(interrupts_enabled == false && "disable_interrupts_test failed!");
}

void halt_test()
{
    running = true;

    halt();

    assert(interrupts_enabled == false && "disable_interrupts_test failed!");
}

void nop_test()
{
    pc = 0;
    nop();

    assert(pc == 1 && "nop_test failed!");
}