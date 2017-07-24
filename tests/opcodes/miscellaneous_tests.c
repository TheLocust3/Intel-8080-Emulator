//
// Created by Jake Kinsella on 6/22/17.
//

#include <assert.h>
#include "../../src/opcodes/miscellaneous.h"
#include "../../src/pins/data_bus.h"
#include "../../src/ram.h"
#include "../../src/pins/address_bus.h"

void input_test();
void output_test();
void enable_interrupts_test();
void disable_interrupts_test();
void halt_test();
void nop_test();

const int TEST_VALUE1 = 10;
const int TEST_VALUE2 = 5;

int main(int argc, const char* argv[])
{
    input_test();
    output_test();
    enable_interrupts_test();
    disable_interrupts_test();
    halt_test();
    nop_test();

    return 0;
}

void input_test()
{
    pc = 0;
    a = 0;
    write_data_bus(TEST_VALUE1);
    initialize_address_bus();
    set_byte_from_address(1, TEST_VALUE2);

    input();

    assert(a == TEST_VALUE1 && "input_test failed!");
    assert(read_address_bus() == 0b0000010100000101 && "input_test failed!");
    assert(pc == 2 && "input_test failed!");
}

void output_test()
{
    pc = 0;
    a = TEST_VALUE1;
    initialize_data_bus();
    initialize_address_bus();
    set_byte_from_address(1, TEST_VALUE2);

    output();

    assert(read_data_bus() == TEST_VALUE1 && "output_test failed!");
    assert(read_address_bus() == 0b0000010100000101 && "input_test failed!");
    assert(pc == 2 && "output_test failed!");
}

void enable_interrupts_test()
{
    pc = 0;
    running = false;

    enable_interrupts();

    assert(interrupts_enabled == true && "enable_interrupts_test failed!");
    assert(pc == 1 && "enable_interrupts_test failed!");
}

void disable_interrupts_test()
{
    pc = 0;
    running = true;

    disable_interrupts();

    assert(interrupts_enabled == false && "disable_interrupts_test failed!");
    assert(pc == 1 && "disable_interrupts_test failed!");
}

void halt_test()
{
    pc = 0;
    running = true;

    halt();

    assert(interrupts_enabled == false && "disable_interrupts_test failed!");
    assert(pc == 1 && "halt_test failed!");
}

void nop_test()
{
    pc = 0;
    nop();

    assert(pc == 1 && "nop_test failed!");
}