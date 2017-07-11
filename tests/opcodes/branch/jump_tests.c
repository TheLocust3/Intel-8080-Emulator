//
// Created by Jake Kinsella on 7/11/17.
//

#include <assert.h>
#include "../../../src/registers.h"
#include "../../../src/ram.h"
#include "../../../src/opcodes/branch/jump.h"

void jump_test();

const int TEST_ADDRESS = 10;

int main(int argc, const char* argv[])
{
    jump_test();

    return 0;
}

void jump_test()
{
    pc = 0;

    set_byte_from_address((uint16_t) (pc + 1), (uint8_t) TEST_ADDRESS);
    set_byte_from_address((uint16_t) (pc + 2), 0);

    jump();

    assert(pc == 10 && "jump_test failed!");
}
