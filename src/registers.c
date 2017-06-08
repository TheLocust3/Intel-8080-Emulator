//
// Created by Jake Kinsella on 4/17/17.
//

#include "registers.h"
#include "common_functions.h"

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

bool is_code_8bit_code(int code)
{
    if (code == A_CODE || code == B_CODE || code == C_CODE || code == D_CODE || code == E_CODE || code == H_CODE || code == L_CODE) {
        return true;
    }

    return false;
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
    }
}

bool is_code_16bit_code(int code)
{
    if (code == BC_CODE || code == DE_CODE || code == HL_CODE || code == SP_CODE) {
        return true;
    }

    return false;
}

uint16_t get_register_pair_from_code(int code)
{
    switch (code) {
        case BC_CODE:
            return combine_bytes(b, c);
        case DE_CODE:
            return combine_bytes(d, e);
        case HL_CODE:
            return combine_bytes(h, l);
        case SP_CODE:
            return sp;
    }
}