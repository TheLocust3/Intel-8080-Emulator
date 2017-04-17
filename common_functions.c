//
// Created by Jake Kinsella on 4/17/17.
//

#include "common_functions.h"

uint16_t combine_bytes(uint8_t high, uint8_t low)
{
    return (high << 8) + low;
}