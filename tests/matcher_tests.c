//
// Created by Jake Kinsella on 6/14/17.
//

#include <stdio.h>
#include "../src/matcher/instruction_template.h"
#include "../src/matcher/matcher.h"
#include "../src/opcode_definitions.h"

void empty_method();
void flip_bool();
int add_template_test();
int simple_match_test();
int simple_run_test();

bool has_flipped = false;

int main(int argc, const char* argv[])
{
    int status = add_template_test();
    status = status && simple_match_test();
    status = status && simple_run_test();

    return !status;
}

int add_template_test()
{
    InstructionTemplate template = new_instruction_template("11111111", &empty_method);
    add_instruction_template(template);

    return get_all_registered_templates()[0].binary_template == template.binary_template; // should be the same templates
}

int simple_match_test()
{
    InstructionTemplate template = new_instruction_template("00000000", &empty_method);
    add_instruction_template(template);

    return match(0) && !match(10); // shouldn't match the random one
}

int simple_run_test()
{
    clear_all_registered_templates();
    has_flipped = false;

    InstructionTemplate template = new_instruction_template("00000000", &flip_bool);
    add_instruction_template(template);

    run_instruction(0, 0, 0, template);

    return has_flipped;
}

void empty_method() {}

void flip_bool()
{
    has_flipped = true;
}
