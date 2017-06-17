//
// Created by Jake Kinsella on 4/16/17.
//

#include <stdio.h>

#include "cpu.h"
#include "opcode_definitions.h"

int main(int argc, const char* argv[])
{
    define_opcodes();
    initialize();

    for (int i = 0; i < 10; i++) {
        cycle();
        print_register_status();
    }

    return 0;
}
