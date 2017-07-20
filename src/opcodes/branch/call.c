//
// Created by Jake Kinsella on 7/14/17.
//

#include "call.h"

void call()
{
    uint8_t low = read_byte_from_address((uint16_t) (pc + 1));
    uint8_t high = read_byte_from_address((uint16_t) (pc + 2));

    push(get_high_order_byte(pc));
    push(get_low_order_byte(pc));

    pc = combine_bytes(high, low);
}

void call_condition(int condition)
{
    switch (condition) {
        case CONDITIONAL_NZ:
            if (!is_zero_flag_set()) {
                call();
            }

            break;
        case CONDITIONAL_Z:
            if (is_zero_flag_set()) {
                call();
            }

            break;
        case CONDITIONAL_NC:
            if (!is_carry_flag_set()) {
                call();
            }

            break;
        case CONDITIONAL_C:
            if (is_carry_flag_set()) {
                call();
            }

            break;
        case CONDITIONAL_PO:
            if (!is_parity_flag_set()) {
                call();
            }

            break;
        case CONDITIONAL_PE:
            if (is_parity_flag_set()) {
                call();
            }

            break;
        case CONDITIONAL_P:
            if (!is_sign_flag_set()) {
                call();
            }

            break;
        case CONDITIONAL_M:
            if (is_sign_flag_set()) {
                call();
            }

            break;
    }
}

void return_plain()
{
    uint8_t low = pop();
    uint8_t high = pop();

    pc = combine_bytes(high, low);
}

void return_condition(int condition)
{
    switch (condition) {
        case CONDITIONAL_NZ:
            if (!is_zero_flag_set()) {
                return_plain();
            }

            break;
        case CONDITIONAL_Z:
            if (is_zero_flag_set()) {
                return_plain();
            }

            break;
        case CONDITIONAL_NC:
            if (!is_carry_flag_set()) {
                return_plain();
            }

            break;
        case CONDITIONAL_C:
            if (is_carry_flag_set()) {
                return_plain();
            }

            break;
        case CONDITIONAL_PO:
            if (!is_parity_flag_set()) {
                return_plain();
            }

            break;
        case CONDITIONAL_PE:
            if (is_parity_flag_set()) {
                return_plain();
            }

            break;
        case CONDITIONAL_P:
            if (!is_sign_flag_set()) {
                return_plain();
            }

            break;
        case CONDITIONAL_M:
            if (is_sign_flag_set()) {
                return_plain();
            }

            break;
    }
}
