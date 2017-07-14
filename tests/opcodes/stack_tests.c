//
// Created by Jake Kinsella on 7/14/17.
//

#include <assert.h>
#include "../../src/registers.h"
#include "../../src/ram.h"
#include "../../src/opcodes/stack.h"

void push_test();

const int TEST_VALUE1 = 10;
const int TEST_VALUE2 = 5;

int main(int argc, const char* argv[])
{
    push_test();

    return 0;
}

void push_test()
{
    pc = 0;
    s = 0xFF;
    p = 0xFF;
    h = TEST_VALUE1;
    l = TEST_VALUE2;

    RegisterPair register_pair = get_register_pair_from_code(HL_CODE);
    push_register_pair(&register_pair);

    uint16_t sp = combine_bytes(s, p);

    assert(sp == (0xFFFF - 2) && "push_test failed!");
    assert(read_byte_from_address((uint16_t) (sp + 1)) == TEST_VALUE1 && "push_test failed!");
    assert(read_byte_from_address(sp) == TEST_VALUE2 && "push_test failed!");
}
