//
// Created by Jake Kinsella on 6/19/17.
//

#include <assert.h>
#include "../../src/matcher/matcher.h"
#include "../../src/registers.h"

void setup();

void dst_run(uint8_t *dst_register);
void src_run(const uint8_t src_register);
void rp_run(RegisterPair *dst_register_pair);
void dst_src_run(uint8_t *dst_register, const uint8_t src_register);

void dst_run_test();
void src_run_test();
void rp_run_test();
void dst_src_run_test();

int value_register1 = 0;
int value_register2 = 0;

const int TEST_VALUE = 10;

int main(int argc, const char* argv[])
{
    dst_run_test();
    src_run_test();
    rp_run_test();
    dst_src_run_test();

    return 0;
}

void dst_run_test()
{
    setup();
    a = TEST_VALUE;

    InstructionTemplate template = new_instruction_template("00DDD000", &dst_run);
    add_instruction_template(template);

    run_instruction(A_CODE, 0, 0, template);

    assert(value_register1 == TEST_VALUE && "Matcher didn't properly pass in register");
}

void src_run_test()
{
    setup();
    a = TEST_VALUE;

    InstructionTemplate template = new_instruction_template("00000SSS", &src_run);
    add_instruction_template(template);

    run_instruction(0, A_CODE, 0, template);

    assert(value_register1 == TEST_VALUE && "Matcher didn't properly pass in register");
}

void rp_run_test()
{
    setup();
    h = 0;
    l = TEST_VALUE;

    InstructionTemplate template = new_instruction_template("00RP0000", &rp_run);
    add_instruction_template(template);

    run_instruction(0, 0, HL_CODE, template);

    assert(value_register1 == TEST_VALUE && "Matcher didn't properly pass in register");
}

void dst_src_run_test()
{
    setup();
    a = TEST_VALUE;
    b = TEST_VALUE + 1;

    InstructionTemplate template = new_instruction_template("00DDDSSS", &dst_src_run);
    add_instruction_template(template);

    run_instruction(A_CODE, B_CODE, 0, template);

    assert(value_register1 == TEST_VALUE && value_register2 == (TEST_VALUE + 1) && "Matcher didn't properly pass in register");
}

void dst_run(uint8_t *dst_register)
{
    value_register1 = *dst_register;
}

void src_run(const uint8_t src_register)
{
    value_register1 = src_register;
}

void rp_run(RegisterPair *dst_register_pair)
{
    value_register1 = combine_bytes(*dst_register_pair->register1, *dst_register_pair->register2);
}

void dst_src_run(uint8_t *dst_register, const uint8_t src_register)
{
    value_register1 = *dst_register;
    value_register2 = src_register;
}

void setup()
{
    clear_all_registered_templates();
    value_register1 = 0;
    value_register2 = 0;
}
