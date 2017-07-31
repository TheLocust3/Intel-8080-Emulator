//
// Created by Jake Kinsella on 7/4/17.
//

#include "miscellaneous_arithmetic.h"
#include "../../log.h"

void add_register_pair_to_HL(const RegisterPair dst_register_pair)
{
    log("DAD rp\n");

    int tmp = combine_bytes(h, l) + combine_bytes(*dst_register_pair.high, *dst_register_pair.low);

    if (tmp > 0xFFFF) {
        tmp = 0XFFFF;
        set_carry_flag(true);
    } else {
        set_carry_flag(false);
    }

    h = get_high_order_byte((uint16_t) tmp);
    l = get_low_order_byte((uint16_t) tmp);

    pc++;
}

void decimal_adjust_accumulator()
{
    log("DAA\n");

    if ((a & 0xF) > 9 || is_aux_carry_flag_set()) {
        a += 6;
    }

    if (((a & 0xF0) >> 4) > 9 || is_carry_flag_set()) {
        a = (uint8_t) ((((a & 0xF0) >> 4) + 6) + (a & 0xF));
    }

    handle_zero_flag(a);
    handle_sign_flag(a);
    handle_parity_flag(a);
    set_carry_flag(false); // TODO: I just took a guess on this one
    set_aux_carry_flag(false);

    pc++;
}
