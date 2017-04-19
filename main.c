//
// Created by Jake Kinsella on 4/16/17.
//

#include <stdio.h>

#include "cpu.h"
#include "ram.h"
#include "registers.h"
#include "opcodes/data_transfer.h"

int main(int argc, const char* argv[])
{
    initialize();

    set_byte(0, 0, 0b00110110);
    set_byte(0, 1, 0b11111101);

    for (int i = 0; i < 10; i++) {
        cycle();
    }

    return 0;
}
