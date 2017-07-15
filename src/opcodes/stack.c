//
// Created by Jake Kinsella on 7/14/17.
//

#include "stack.h"

void push(uint8_t value);
uint8_t flag_status_word();

// TODO: Prevent sp from being passed in
void push_register_pair(RegisterPair *dst_register_pair)
{
    push(*dst_register_pair->high);
    push(*dst_register_pair->low);
}

void push_processor_status_word()
{
    push(a);
    push(flag_status_word());
}

uint8_t flag_status_word()
{
    uint8_t status = 0;


    return 0;
}

void push(uint8_t value) {
    uint16_t sp = combine_bytes(s, p);

    set_byte_from_address((uint16_t) (sp - 1), value);

    sp--;
    s = get_high_order_byte(sp);
    p = get_low_order_byte(sp);
}
