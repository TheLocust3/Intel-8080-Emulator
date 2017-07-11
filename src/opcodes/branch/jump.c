//
// Created by Jake Kinsella on 7/11/17.
//

#include "jump.h"

void jump()
{
    uint8_t low = read_byte_from_address((uint16_t) (pc + 1));
    uint8_t high = read_byte_from_address((uint16_t) (pc + 2));

    pc = combine_bytes(high, low);
}
