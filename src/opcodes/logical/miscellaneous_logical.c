//
// Created by Jake Kinsella on 7/8/17.
//

#include "miscellaneous_logical.h"

void handle_flags_cmp(const int final_value, const int value1, const int value2);

void compare_register(const uint8_t src_register)
{
    printf("CMP r\n");

    int result = a - src_register;

    handle_flags_cmp(result, a, src_register);

    pc++;
}

void handle_flags_cmp(const int final_value, const int value1, const int value2) {
    handle_zero_flag(final_value);
    handle_sign_flag(final_value);
    handle_carry_flag_cmp(value1, value2);
    handle_aux_carry_flag_sub(value1, value2);
    handle_parity_flag(final_value);
}
