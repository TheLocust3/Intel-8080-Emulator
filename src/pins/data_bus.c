//
// Created by Jake Kinsella on 7/23/17.
//

#include "data_bus.h"

void initialize_data_bus()
{
    write_pin(D0, false);
    write_pin(D1, false);
    write_pin(D2, false);
    write_pin(D3, false);
    write_pin(D4, false);
    write_pin(D5, false);
    write_pin(D6, false);
    write_pin(D7, false);
}

void write_data_bus(uint8_t byte)
{
    write_pin(D0, (bool) get_bit_16bit(byte, 0));
    write_pin(D1, (bool) get_bit_16bit(byte, 1));
    write_pin(D2, (bool) get_bit_16bit(byte, 2));
    write_pin(D3, (bool) get_bit_16bit(byte, 3));
    write_pin(D4, (bool) get_bit_16bit(byte, 4));
    write_pin(D5, (bool) get_bit_16bit(byte, 5));
    write_pin(D6, (bool) get_bit_16bit(byte, 6));
    write_pin(D7, (bool) get_bit_16bit(byte, 7));
}

uint8_t read_data_bus()
{
    uint8_t byte = 0;
    byte = set_bit(byte, 0, read_pin(D0));
    byte = set_bit(byte, 1, read_pin(D1));
    byte = set_bit(byte, 2, read_pin(D2));
    byte = set_bit(byte, 3, read_pin(D3));
    byte = set_bit(byte, 4, read_pin(D4));
    byte = set_bit(byte, 5, read_pin(D5));
    byte = set_bit(byte, 6, read_pin(D6));
    byte = set_bit(byte, 7, read_pin(D7));

    return byte;
}
