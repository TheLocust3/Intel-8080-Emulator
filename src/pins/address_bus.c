//
// Created by Jake Kinsella on 7/24/17.
//

#include "address_bus.h"

void initialize_address_bus()
{
    write_pin(A0, false);
    write_pin(A1, false);
    write_pin(A2, false);
    write_pin(A3, false);
    write_pin(A4, false);
    write_pin(A5, false);
    write_pin(A6, false);
    write_pin(A7, false);
    write_pin(A8, false);
    write_pin(A9, false);
    write_pin(A10, false);
    write_pin(A11, false);
    write_pin(A12, false);
    write_pin(A13, false);
    write_pin(A14, false);
    write_pin(A15, false);
}

void write_address_bus(uint16_t value)
{
    write_pin(A0, (bool) get_bit_16bit(value, 0));
    write_pin(A1, (bool) get_bit_16bit(value, 1));
    write_pin(A2, (bool) get_bit_16bit(value, 2));
    write_pin(A3, (bool) get_bit_16bit(value, 3));
    write_pin(A4, (bool) get_bit_16bit(value, 4));
    write_pin(A5, (bool) get_bit_16bit(value, 5));
    write_pin(A6, (bool) get_bit_16bit(value, 6));
    write_pin(A7, (bool) get_bit_16bit(value, 7));
    write_pin(A8, (bool) get_bit_16bit(value, 8));
    write_pin(A9, (bool) get_bit_16bit(value, 9));
    write_pin(A10, (bool) get_bit_16bit(value, 10));
    write_pin(A11, (bool) get_bit_16bit(value, 11));
    write_pin(A12, (bool) get_bit_16bit(value, 12));
    write_pin(A13, (bool) get_bit_16bit(value, 13));
    write_pin(A14, (bool) get_bit_16bit(value, 14));
    write_pin(A15, (bool) get_bit_16bit(value, 15));
}

uint16_t read_address_bus()
{
    uint16_t value = 0;
    value = set_bit_16bit(value, 0, read_pin(A0));
    value = set_bit_16bit(value, 1, read_pin(A1));
    value = set_bit_16bit(value, 2, read_pin(A2));
    value = set_bit_16bit(value, 3, read_pin(A3));
    value = set_bit_16bit(value, 4, read_pin(A4));
    value = set_bit_16bit(value, 5, read_pin(A5));
    value = set_bit_16bit(value, 6, read_pin(A6));
    value = set_bit_16bit(value, 7, read_pin(A7));
    value = set_bit_16bit(value, 8, read_pin(A8));
    value = set_bit_16bit(value, 9, read_pin(A9));
    value = set_bit_16bit(value, 10, read_pin(A10));
    value = set_bit_16bit(value, 11, read_pin(A11));
    value = set_bit_16bit(value, 12, read_pin(A12));
    value = set_bit_16bit(value, 13, read_pin(A13));
    value = set_bit_16bit(value, 14, read_pin(A14));
    value = set_bit_16bit(value, 15, read_pin(A15));

    return value;
}

