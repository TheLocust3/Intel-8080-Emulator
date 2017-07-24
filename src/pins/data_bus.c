//
// Created by Jake Kinsella on 7/23/17.
//

#include "data_bus.h"

void initialize_data_bus()
{
    data_bus = 0;
}

void write_data_bus(uint8_t byte)
{
    data_bus = byte;
}

uint8_t read_data_bus()
{
    return data_bus;
}
