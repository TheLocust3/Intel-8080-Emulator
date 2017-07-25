//
// Created by Jake Kinsella on 7/14/17.
//

#include <stdlib.h>
#include "stack.h"
#include "../flags.h"
#include "../registers.h"

uint8_t flag_status_word();

void push_register_pair(RegisterPair *dst_register_pair)
{
    if (dst_register_pair->high == &s ||  dst_register_pair->low == &p) {
        printf("SP cannot be pushed!\n");
        return;
    }

    printf("PUSH rp\n");

    push(*dst_register_pair->high);
    push(*dst_register_pair->low);

    pc++;
}

void push_processor_status_word()
{
    printf("PUSH PSW\n");

    push(a);
    push(flag_status_word());

    pc++;
}

void pop_register_pair(RegisterPair *src_register_pair)
{
    if (src_register_pair->high == &s ||  src_register_pair->low == &p) {
        printf("SP cannot be popped!\n");
        return;
    }

    printf("POP rp\n");

    *src_register_pair->low = pop();
    *src_register_pair->high = pop();
}

void pop_processor_status_word()
{
    printf("POP PSW\n");

    uint8_t status = pop();
    set_carry_flag((bool) get_bit(status, 0));
    set_parity_flag((bool) get_bit(status, 2));
    set_aux_carry_flag((bool) get_bit(status, 4));
    set_zero_flag((bool) get_bit(status, 6));
    set_sign_flag((bool) get_bit(status, 7));

    a = pop();

    pc++;
}

void exchange_stack_top_with_HL()
{
    printf("XTHL\n");

    uint16_t sp = combine_bytes(s, p);

    uint8_t tmp_low = read_byte_from_address(sp);
    uint8_t tmp_high = read_byte_from_address((uint16_t) (sp + 1));

    set_byte_from_address(sp, l);
    set_byte_from_address((uint16_t) (sp + 1), h);

    l = tmp_low;
    h = tmp_high;

    pc++;
}

void move_HL_to_SP()
{
    printf("SPHL\n");

    s = h;
    p = l;

    pc++;
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
    sp--;

    set_byte_from_address(sp, value);

    s = get_high_order_byte(sp);
    p = get_low_order_byte(sp);
}

uint8_t pop()
{
    uint16_t sp = combine_bytes(s, p);

    sp++;
    s = get_high_order_byte(sp);
    p = get_low_order_byte(sp);

    return read_byte_from_address((uint16_t) (sp - 1));
}
