//
// Created by Jake Kinsella on 6/17/17.
//

#include <assert.h>
#include "../../src/matcher/matcher.h"

void setup();
void flip_bool();

void simple_run_test();
void dst_run_test();
void src_run_test();
void rp_run_test();
void dst_and_src_run_test();
void none_run_test();
void condition_run_test();

bool has_flipped = false;

int main(int argc, const char* argv[])
{
    simple_run_test();
    dst_run_test();
    src_run_test();
    rp_run_test();
    dst_and_src_run_test();
    condition_run_test();
    none_run_test();

    return 0;
}

void simple_run_test()
{
    setup();

    InstructionTemplate template = new_instruction_template("00000000", &flip_bool);
    add_instruction_template(template);

    run_instruction(0, 0, 0, 0, template);

    assert(has_flipped && "simple_run_test failed!");
}

void dst_run_test()
{
    setup();

    InstructionTemplate template = new_instruction_template("00DDD000", &flip_bool);
    add_instruction_template(template);

    run_instruction(0, 0, 0, 0, template);

    assert(has_flipped && "dst_run_test failed!");
}

void src_run_test()
{
    setup();

    InstructionTemplate template = new_instruction_template("00000SSS", &flip_bool);
    add_instruction_template(template);

    run_instruction(0, 0, 0, 0, template);

    assert(has_flipped && "src_run_test failed!");
}

void rp_run_test()
{
    setup();

    InstructionTemplate template = new_instruction_template("00RP0000", &flip_bool);
    add_instruction_template(template);

    run_instruction(0, 0, 0, 0, template);

    assert(has_flipped && "rp_run_test failed!");
}

void dst_and_src_run_test()
{
    setup();

    InstructionTemplate template = new_instruction_template("00DDDSSS", &flip_bool);
    add_instruction_template(template);

    run_instruction(0, 0, 0, 0, template);

    assert(has_flipped && "dst_and_src_run_test failed!");
}

void condition_run_test()
{
    setup();

    InstructionTemplate template = new_instruction_template("00CCC000", &flip_bool);
    add_instruction_template(template);

    run_instruction(0, 0, 0, 0, template);

    assert(has_flipped && "condition_run_test failed!");
}

void none_run_test()
{
    setup();

    InstructionTemplate template = new_instruction_template("00000000", &flip_bool);
    add_instruction_template(template);

    run_instruction(0, 0, 0, 0, template);

    assert(has_flipped && "none_run_test failed!");
}

void flip_bool()
{
    has_flipped = true;
}

void setup()
{
    clear_all_registered_templates();
    has_flipped = false;
}
