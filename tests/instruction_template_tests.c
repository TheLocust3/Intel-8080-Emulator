//
// Created by Jake Kinsella on 6/15/17.
//

#include <stdio.h>
#include "../src/matcher/instruction_template.h"

void empty_method();
int blank_template_creation_test();

int main(int argc, const char* argv[])
{
    int status = blank_template_creation_test();
    return !status;
}

int blank_template_creation_test()
{
    InstructionTemplate template = new_instruction_template("00000000", &empty_method);

    return template.binary_template == 0 && !template.has_rp && !template.has_dst && !template.has_src;
}

void empty_method()
{

}
