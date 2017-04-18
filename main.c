//
// Created by Jake Kinsella on 4/16/17.
//

#include <stdio.h>

#include "cpu.h"
#include "ram.h"
#include "registers.h"
#include "opcodes/move.h"

int main(int argc, const char* argv[])
{
    initialize();

    set_byte(0, 0, 0b01111000);

    for (int i = 0; i < 10; i++) {
        cycle();
    }

    return 0;
}
