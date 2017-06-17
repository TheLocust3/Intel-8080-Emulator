//
// Created by Jake Kinsella on 6/14/17.
//

#include <stdio.h>
#include <assert.h>
#include "../src/matcher/instruction_template.h"
#include "../src/matcher/matcher.h"
#include "../src/opcode_definitions.h"

void empty_method();
void flip_bool();

void add_template_test();
void simple_match_test();
void simple_run_test();

bool has_flipped = false;

int main(int argc, const char* argv[])
{
    add_template_test();
    simple_match_test();
    simple_run_test();

    return 0;
}

void add_template_test()
{
    InstructionTemplate template = new_instruction_template("11111111", &empty_method);
    add_instruction_template(template);

    assert(get_all_registered_templates()[0].binary_template == template.binary_template && "Generated template was not registered with matcher");
}

void simple_match_test()
{
    InstructionTemplate template = new_instruction_template("00000000", &empty_method);
    add_instruction_template(template);

    assert(match(0) && "Matcher failed to match correct instruction");
    assert(!match(10) && "Matched matched incorrect instruction");
}

void simple_run_test()
{
    clear_all_registered_templates();
    has_flipped = false;

    InstructionTemplate template = new_instruction_template("00000000", &flip_bool);
    add_instruction_template(template);

    run_instruction(0, 0, 0, template);

    assert(has_flipped && "Template function was not run");
}

void empty_method() {}

void flip_bool()
{
    has_flipped = true;
}
