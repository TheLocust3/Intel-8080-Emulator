//
// Created by Jake Kinsella on 7/4/17.
//

#include <assert.h>
#include "../../src/registers.h"
#include "../../src/flags.h"
#include "../../src/opcodes/arithmetic/miscellaneous_arithmetic.h"

void add_register_pair_to_HL_test();

const int TEST_VALUE = 10;

int main(int argc, const char* argv[])
{
    add_register_pair_to_HL_test();

    return 0;
}

void add_register_pair_to_HL_test()
{
    pc = 0;
    h = 0;
    l = 0;
    b = 0;
    c = TEST_VALUE;

    add_register_pair_to_HL(create_register_pair(&b, &c));

    assert(h == 0 && l == TEST_VALUE && "add_register_pair_to_HL_test failed!");
    assert(pc == 1 && "add_register_pair_to_HL_test failed!");
    assert(!get_carry_flag() && "add_register_pair_to_HL_test failed!");
}
