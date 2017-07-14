//
// Created by Jake Kinsella on 7/14/17.
//

#include "stack.h"

void push(uint16_t value);

// TODO: Prevent sp from being passed in
void push_register_pair(RegisterPair *dst_register_pair)
{
    push(combine_bytes(*dst_register_pair->high, *dst_register_pair->low));
}

void push(uint16_t value)
{
    uint16_t sp = combine_bytes(s, p);

    set_byte_from_address((uint16_t) (sp - 1), get_high_order_byte(value));
    set_byte_from_address((uint16_t) (sp - 2), get_low_order_byte(value));

    sp -= 2;
    s = get_high_order_byte(sp);
    p = get_low_order_byte(sp);
}
