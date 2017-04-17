//
// Created by Jake Kinsella on 4/17/17.
//

#include "ram.h"
#include "common_functions.h"

void initialize_ram()
{
    for (int i = 0; i < BYTES_OF_RAM; i++) {
        ram[i] = 0;
    }
}

uint8_t get_byte(uint8_t high, uint8_t low)
{
    return ram[combine_bytes(high, low)];
}

uint8_t get_byte_from_address(uint16_t address)
{
    return ram[address];
}