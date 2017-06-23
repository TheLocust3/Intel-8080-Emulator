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

uint8_t read_byte(uint8_t address_high, uint8_t address_low)
{
    return ram[combine_bytes(address_high, address_low)];
}

uint8_t read_byte_from_address(uint16_t address)
{
    return ram[address];
}

uint16_t read_16bits_from_address(uint16_t address)
{
    return combine_bytes(read_byte_from_address((uint16_t) (address + 1)), read_byte_from_address((uint16_t) (address)));
}

void set_byte(uint8_t address_high, uint8_t address_low, uint8_t value)
{
    ram[combine_bytes(address_high, address_low)] = value;
}

void set_byte_from_address(uint16_t address, uint8_t value)
{
    ram[address] = value;
}