//
// Created by Jake Kinsella on 7/11/17.
//

#include "jump.h"
#include "../../flags.h"
#include "../../log.h"

void jump()
{
    log("JMP addr\n");

    uint8_t low = read_byte_from_address((uint16_t) (pc + 1));
    uint8_t high = read_byte_from_address((uint16_t) (pc + 2));

    pc = combine_bytes(high, low);
}

void jump_condition(int condition)
{
    log("Jcondition addr\n");

    uint8_t low = read_byte_from_address((uint16_t) (pc + 1));
    uint8_t high = read_byte_from_address((uint16_t) (pc + 2));
    uint16_t address = combine_bytes(high, low);

    switch (condition) {
        case CONDITIONAL_NZ:
            if (!is_zero_flag_set()) {
                pc = address;
            }

            break;
        case CONDITIONAL_Z:
            if (is_zero_flag_set()) {
                pc = address;
            }

            break;
        case CONDITIONAL_NC:
            if (!is_carry_flag_set()) {
                pc = address;
            }

            break;
        case CONDITIONAL_C:
            if (is_carry_flag_set()) {
                pc = address;
            }

            break;
        case CONDITIONAL_PO:
            if (!is_parity_flag_set()) {
                pc = address;
            }

            break;
        case CONDITIONAL_PE:
            if (is_parity_flag_set()) {
                pc = address;
            }

            break;
        case CONDITIONAL_P:
            if (!is_sign_flag_set()) {
                pc = address;
            }

            break;
        case CONDITIONAL_M:
            if (is_sign_flag_set()) {
                pc = address;
            }

            break;
    }
}
