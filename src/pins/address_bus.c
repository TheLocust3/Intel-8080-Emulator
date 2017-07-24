//
// Created by Jake Kinsella on 7/24/17.
//

#include "address_bus.h"

void initialize_address_bus()
{
    address_bus = 0;
}

void write_address_bus(uint8_t byte)
{
    address_bus = byte;
}

uint8_t read_address_bus()
{
    return address_bus;
}

