//
// Created by Jake Kinsella on 7/23/17.
//

#include "data_bus.h"

void initialize_bus()
{
    bus = 0;
}

void write_bus(uint8_t byte)
{
    bus = byte;
}

uint8_t read_bus()
{
    return bus;
}
