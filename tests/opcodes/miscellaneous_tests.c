//
// Created by Jake Kinsella on 6/22/17.
//

#include <assert.h>
#include "../../src/opcodes/miscellaneous.h"
#include "../../src/registers.h"

void nop_test();

int main(int argc, const char* argv[])
{
    nop_test();

    return 0;
}

void nop_test()
{
    pc = 0;
    nop();

    assert(pc == 1 && "nop_test failed!");
}