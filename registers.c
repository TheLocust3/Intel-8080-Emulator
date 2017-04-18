//
// Created by Jake Kinsella on 4/17/17.
//

#include "registers.h"

void initialize_registers()
{
    pc = 0;
    sp = 0;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    h = 0;
    l = 0;
}

uint8_t get_register_from_code(int code)
{
    switch (code) {
        case A_CODE:
            return a;
        case B_CODE:
            return b;
        case C_CODE:
            return c;
        case D_CODE:
            return d;
        case E_CODE:
            return e;
        case H_CODE:
            return h;
        case L_CODE:
            return l;
        default:
            return NULL_REGISTER;
    }
}