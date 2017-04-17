//
// Created by Jake Kinsella on 4/16/17.
//

#include <stdio.h>
#include "registers.h"
#include "ram.h"
#include "opcodes/move.h"

int main(int argc, const char* argv[])
{
    initialize_registers();
    initialize_ram();

    return 0;
}
