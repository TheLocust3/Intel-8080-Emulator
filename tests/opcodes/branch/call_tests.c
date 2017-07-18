//
// Created by Jake Kinsella on 7/14/17.
//

#include <assert.h>
#include "../../../src/registers.h"
#include "../../../src/ram.h"
#include "../../../src/opcodes/branch/call.h"
#include "../../../src/opcodes/stack.h"
#include "../../../src/flags.h"

void call_test();

const int TEST_ADDRESS = 10;
const int TEST_ADDRESS2 = 5;

int main(int argc, const char* argv[])
{
    call_test();

    return 0;
}

void call_test()
{
    pc = TEST_ADDRESS2;
    s = 0xFF;
    p = 0xFF;

    set_byte_from_address((uint16_t) (pc + 1), (uint8_t) TEST_ADDRESS);
    set_byte_from_address((uint16_t) (pc + 2), 0);

    call();

    assert(pc == 10 && "call_test failed!");
    assert(combine_bytes(s, p) == 0xFFFD && "call_test failed!");
    assert(pop() == 0 && "call_test failed!");
    assert(pop() == TEST_ADDRESS2 && "call_test failed!");
}
