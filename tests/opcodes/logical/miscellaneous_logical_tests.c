//
// Created by Jake Kinsella on 7/8/17.
//

#include <assert.h>
#include "../../../src/registers.h"
#include "../../../src/opcodes/logical/miscellaneous_logical.h"
#include "../../../src/ram.h"

void generic_asserts_cmp();

void cmp_register_test();
void cmp_memory_test();

const int TEST_VALUE1 = 10;
const int TEST_VALUE2 = 5;

int main(int argc, const char* argv[])
{
    cmp_register_test();
    cmp_memory_test();

    return 0;
}

void cmp_register_test()
{
    pc = 0;
    f = 0;
    a = TEST_VALUE1;
    b = TEST_VALUE2;

    compare_register(b);

    assert(pc == 1 && "cmp_register_test failed!");

    generic_asserts_cmp();
}

void cmp_memory_test()
{
    pc = 0;
    f = 0;
    a = TEST_VALUE1;
    h = 0;
    l = 0;

    set_byte(h, l, TEST_VALUE2);

    compare_memory();

    assert(pc == 1 && "cmp_register_test failed!");

    generic_asserts_cmp();
}

void generic_asserts_cmp() {
    assert(!get_zero_flag() && "generic_asserts_cmp failed");
    assert(!get_sign_flag() && "generic_asserts_cmp failed");
    assert(get_parity_flag() && "generic_asserts_cmp failed");
    assert(!get_carry_flag() && "generic_asserts_cmp failed");
    assert(!get_aux_carry_flag() && "generic_asserts_cmp failed");
}
