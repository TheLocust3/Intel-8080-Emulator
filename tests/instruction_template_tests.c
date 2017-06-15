//
// Created by Jake Kinsella on 6/15/17.
//

#include <stdio.h>
#include "../src/matcher/instruction_template.h"

void empty_method();
int blank_template_creation_test();
int rp_template_creation_test();
int dst_template_creation_test();
int src_template_creation_test();
int dst_and_src_template_creation_test();

int main(int argc, const char* argv[])
{
    int status = blank_template_creation_test();
    status = status && rp_template_creation_test();
    status = status && dst_template_creation_test();
    status = status && src_template_creation_test();
    status = status && dst_and_src_template_creation_test();

    return !status;
}

int blank_template_creation_test()
{
    InstructionTemplate template = new_instruction_template("00000000", &empty_method);

    return template.binary_template == 0 && !template.has_rp && !template.has_dst && !template.has_src;
}

int rp_template_creation_test()
{
    InstructionTemplate template = new_instruction_template("00RP0000", &empty_method);

    return template.binary_template == 0 && template.has_rp && !template.has_dst && !template.has_src;
}

int dst_template_creation_test()
{
    InstructionTemplate template = new_instruction_template("00DDD000", &empty_method);

    return template.binary_template == 0 && !template.has_rp && template.has_dst && !template.has_src;
}

int src_template_creation_test()
{
    InstructionTemplate template = new_instruction_template("00000SSS", &empty_method);

    return template.binary_template == 0 && !template.has_rp && !template.has_dst && template.has_src;
}

int dst_and_src_template_creation_test()
{
    InstructionTemplate template = new_instruction_template("00DDDSSS", &empty_method);

    return template.binary_template == 0 && !template.has_rp && template.has_dst && template.has_src;
}

void empty_method() {}
