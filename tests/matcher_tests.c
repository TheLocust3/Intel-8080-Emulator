//
// Created by Jake Kinsella on 6/14/17.
//

#include <stdio.h>
#include "../src/matcher/instruction_template.h"
#include "../src/matcher/matcher.h"

void empty_method();
int add_template_test();
int simple_match_test();

int main(int argc, const char* argv[])
{
    int status = add_template_test();
    status = status && simple_match_test();

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

void empty_method() {}
