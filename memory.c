//
// Created by Jake Kinsella on 4/17/17.
//

#include "memory.h"

void initialize_ram()
{
    for (int i = 0; i < BYTES_OF_RAM; i++) {
        ram[i] = 0;
    }
}