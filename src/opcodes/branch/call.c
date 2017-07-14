//
// Created by Jake Kinsella on 7/14/17.
//

#include "call.h"

void call()
{
    uint8_t low = read_byte_from_address((uint16_t) (pc + 1));
    uint8_t high = read_byte_from_address((uint16_t) (pc + 2));

    // adjust stack

    pc = combine_bytes(high, low);
}
