//
// Created by Jake Kinsella on 7/31/17.
//

#include <assert.h>
#include "../src/opcodes/data_transfer.h"

void swap_registers_test();

int main(int argc, const char* argv[])
{
    swap_registers_test();

    return 0;
}

void swap_registers_test()
{
    h = 10;
    l = 5;
    d = 0;
    e = 0;

    exchange_HL_DE();

    assert(d == 10 && h == 0 && "swap_registers_test failed!");
    assert(e == 5 && l == 0 && "swap_registers_test failed!");

    h = 99;
    l = 50;

    assert(h == 99 && d == 10 && "swap_registers_test failed!");
    assert(l == 50 && e == 5 && "swap_registers_test failed!");
}
