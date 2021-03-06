//
// Created by Jake Kinsella on 6/14/17.
//

#include <assert.h>
#include "../../src/matcher/instruction_template.h"
#include "../../src/matcher/matcher.h"

void empty_method();

void add_template_test();
void simple_match_test();

int main(int argc, const char* argv[])
{
    add_template_test();
    simple_match_test();

    return 0;
}

void add_template_test()
{
    InstructionTemplate template = new_instruction_template("11111111", &empty_method);
    add_instruction_template(template);

    assert(get_all_registered_templates()[0].binary_template == template.binary_template && "add_template_test failed");
}

void simple_match_test()
{
    InstructionTemplate template = new_instruction_template("00000000", &empty_method);
    add_instruction_template(template);

    assert(match(0) != -1 && "Matcher failed to match correct instruction");
    assert(match(10) == -1 && "Matched matched incorrect instruction");
}

void empty_method() {}
