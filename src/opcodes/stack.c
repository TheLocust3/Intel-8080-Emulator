//
// Created by Jake Kinsella on 7/14/17.
//

#include "stack.h"
#include "../flags.h"
#include "../registers.h"

void push(uint8_t value);
uint8_t pop();
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

// TODO: Prevent sp from being passed in
void pop_register_pair(RegisterPair *src_register_pair)
{
    *src_register_pair->low = pop();
    *src_register_pair->high = pop();
}

uint8_t flag_status_word()
{
    uint8_t status = 0;
    status = set_bit(status, 0, (bool) get_carry_flag());
    status = set_bit(status, 1, true);
    status = set_bit(status, 2, (bool) get_parity_flag());
    status = set_bit(status, 3, false);
    status = set_bit(status, 4, (bool) get_aux_carry_flag());
    status = set_bit(status, 5, false);
    status = set_bit(status, 6, (bool) get_zero_flag());
    status = set_bit(status, 7, (bool) get_sign_flag());

    return status;
}

void push(uint8_t value)
{
    uint16_t sp = combine_bytes(s, p);

    set_byte_from_address((uint16_t) (sp - 1), value);

    sp--;
    s = get_high_order_byte(sp);
    p = get_low_order_byte(sp);
}

// TODO: Figure out if the memory needs to be erased
uint8_t pop()
{
    uint16_t sp = combine_bytes(s, p);

    sp++;
    s = get_high_order_byte(sp);
    p = get_low_order_byte(sp);

    return read_byte_from_address((uint16_t) (sp - 1));
}
