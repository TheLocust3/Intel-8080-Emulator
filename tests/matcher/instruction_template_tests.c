//
// Created by Jake Kinsella on 6/15/17.
//

#include <assert.h>
#include "../../src/matcher/instruction_template.h"

void empty_method();

void blank_template_creation_test();
void rp_template_creation_test();
void dst_template_creation_test();
void src_template_creation_test();
void dst_and_src_template_creation_test();
void condition_template_creation_test();

int main(int argc, const char* argv[])
{
    blank_template_creation_test();
    rp_template_creation_test();
    dst_template_creation_test();
    src_template_creation_test();
    dst_and_src_template_creation_test();
    condition_template_creation_test();

    return 0;
}

void blank_template_creation_test()
{
    InstructionTemplate template = new_instruction_template("00000000", &empty_method);

    assert(template.binary_template == 0 && "Failed to create correct binary template");
    assert(!template.has_rp && "Failed to determine that there is no RP");
    assert(!template.has_dst && "Failed to determine that there is no DST");
    assert(!template.has_src && "Failed to determine that there is no SRC");
    assert(!template.has_condition && "Failed to determine that there is a condition");
}

void rp_template_creation_test()
{
    InstructionTemplate template = new_instruction_template("00RP0000", &empty_method);

    assert(template.binary_template == 0 && "Failed to create correct binary template");
    assert(template.has_rp && "Failed to determine that there is a RP");
    assert(!template.has_dst && "Failed to determine that there is no DST");
    assert(!template.has_src && "Failed to determine that there is no SRC");
    assert(!template.has_condition && "Failed to determine that there is a condition");
}

void dst_template_creation_test()
{
    InstructionTemplate template = new_instruction_template("00DDD000", &empty_method);

    assert(template.binary_template == 0 && "Failed to create correct binary template");
    assert(!template.has_rp && "Failed to determine that there is no RP");
    assert(template.has_dst && "Failed to determine that there is a DST");
    assert(!template.has_src && "Failed to determine that there is no SRC");
    assert(!template.has_condition && "Failed to determine that there is a condition");
}

void src_template_creation_test()
{
    InstructionTemplate template = new_instruction_template("00000SSS", &empty_method);

    assert(template.binary_template == 0 && "Failed to create correct binary template");
    assert(!template.has_rp && "Failed to determine that there is no RP");
    assert(!template.has_dst && "Failed to determine that there is no DST");
    assert(template.has_src && "Failed to determine that there is a SRC");
    assert(!template.has_condition && "Failed to determine that there is a condition");
}

void dst_and_src_template_creation_test()
{
    InstructionTemplate template = new_instruction_template("00DDDSSS", &empty_method);

    assert(template.binary_template == 0 && "Failed to create correct binary template");
    assert(!template.has_rp && "Failed to determine that there is no RP");
    assert(template.has_dst && "Failed to determine that there is a DST");
    assert(template.has_src && "Failed to determine that there is a SRC");
    assert(!template.has_condition && "Failed to determine that there is a condition");
}

void condition_template_creation_test()
{
    InstructionTemplate template = new_instruction_template("00CCC000", &empty_method);

    assert(template.binary_template == 0 && "Failed to create correct binary template");
    assert(!template.has_rp && "Failed to determine that there is no RP");
    assert(!template.has_dst && "Failed to determine that there is a DST");
    assert(!template.has_src && "Failed to determine that there is no SRC");
    assert(template.has_condition && "Failed to determine that there is a condition");
}

void empty_method() {}
