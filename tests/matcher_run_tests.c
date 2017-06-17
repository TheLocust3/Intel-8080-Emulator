//
// Created by Jake Kinsella on 6/17/17.
//

#include <assert.h>
#include "../src/matcher/matcher.h"

void flip_bool();
void simple_run_test();

bool has_flipped = false;

int main(int argc, const char* argv[])
{
    simple_run_test();

    return 0;
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

void flip_bool()
{
    has_flipped = true;
}
