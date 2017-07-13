//
// Created by Jake Kinsella on 7/11/17.
//

#include "jump.h"

void jump()
{
    uint8_t low = read_byte_from_address((uint16_t) (pc + 1));
    uint8_t high = read_byte_from_address((uint16_t) (pc + 2));

    pc = combine_bytes(high, low);
}

void jump_condition(int condition) {
    uint8_t low = read_byte_from_address((uint16_t) (pc + 1));
    uint8_t high = read_byte_from_address((uint16_t) (pc + 2));
    uint16_t address = combine_bytes(high, low);

    switch (condition) {
        case CONDITIONAL_NZ:
            break;
        case CONDITIONAL_Z:
            break;
        case CONDITIONAL_NC:
            break;
        case CONDITIONAL_C:
            break;
        case CONDITIONAL_PO:
            break;
        case CONDITIONAL_PE:
            break;
        case CONDITIONAL_P:
            break;
        case CONDITIONAL_M:
            break;
    }
}
