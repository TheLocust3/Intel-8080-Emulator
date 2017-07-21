//
// Created by Jake Kinsella on 7/20/17.
//

#include <assert.h>
#include "../../../src/registers.h"
#include "../../../src/ram.h"
#include "../../../src/opcodes/branch/miscellaneous_branch.h"

void restart_test();
void jump_HL_indirect_test();

const int TEST_ADDRESS = 10;

int main(int argc, const char* argv[])
{
    restart_test();
    jump_HL_indirect_test();
}

void restart_test()
{
    pc = 0;
    s = 0xFF;
    p = 0xFF;

    restart(0b001);

    assert(pc == 8 && "restart_test failed!");
}

void jump_HL_indirect_test()
{
    pc = 0;
    h = 0;
    l = TEST_ADDRESS;

    jump_HL_indirect();

    assert(pc == TEST_ADDRESS && "restart_test failed!");
}
