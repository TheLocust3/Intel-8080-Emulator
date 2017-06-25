//
// Created by Jake Kinsella on 6/25/17.
//

#include "add.h"

void add_8bit(uint8_t *dst, const uint8_t src);

void add_register(const uint8_t src_register)
{
    add_8bit(&a, src_register);
}

void add_8bit(uint8_t *dst, const uint8_t src)
{
    *dst += src;
}
