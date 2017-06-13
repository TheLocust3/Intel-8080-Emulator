//
// Created by Jake Kinsella on 4/17/17.
//

#include "registers.h"
#include "common_functions.h"

RegisterPair create_register_pair(uint8_t *register1, uint8_t *register2);

void initialize_registers()
{
    pc = 0;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    h = 0;
    l = 0;
    s = 0;
    p = 0;
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

RegisterPair get_register_pair_from_code(int code)
{
    switch (code) {
        case BC_CODE:
            return create_register_pair(&b, &c);
        case DE_CODE:
            return create_register_pair(&d, &e);
        case HL_CODE:
            return create_register_pair(&h, &l);
        case SP_CODE:
            return create_register_pair(&s, &p);
    }
}

bool does_register_pair_equal(RegisterPair register_pair, uint16_t value)
{
    return *register_pair.register1 == get_high_order_byte(value) && *register_pair.register2 == get_low_order_byte(value);
}

RegisterPair create_register_pair(uint8_t *register1, uint8_t *register2)
{
    RegisterPair tmp;
    tmp.register1 = register1;
    tmp.register2 = register2;

    return tmp;
}