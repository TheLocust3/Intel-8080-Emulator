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

    set_byte(0, 0, 0b00111010);
    set_byte(0, 1, 0b10000000);
    set_byte(0, 2, 0b00000000);
    set_byte(0, 0b10000000, 100);

    for (int i = 0; i < 10; i++) {
        cycle();
        print_register_status();
    }

    return 0;
}
