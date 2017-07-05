//
// Created by Jake Kinsella on 7/5/17.
//

#include "bitwise.h"
#include "../../ram.h"

void handle_bitwise_flags(const uint8_t result, const uint8_t value1, const uint8_t value2);
void and(const uint8_t src);

void and_register(const uint8_t src_register)
{
    printf("ANA r\n");

    const uint8_t tmp = a;

    and(src_register);

    handle_bitwise_flags(a, tmp, src_register);
    set_carry_flag(false);

    pc++;
}

void and_memory()
{
    printf("ANA (HL)\n");

    const uint8_t tmp = a;
    const uint8_t data = read_byte(h, l);

    and(data);

    handle_bitwise_flags(a, tmp, data);
    set_carry_flag(false);

    pc++;
}

void and_immediate()
{
    printf("ANA data\n");

    const uint8_t tmp = a;
    const uint8_t data = read_byte_from_address(pc);

    and(data);

    handle_bitwise_flags(a, tmp, data);
    set_carry_flag(false);
    set_aux_carry_flag(false);

    pc++;
}

void and(const uint8_t src)
{
    a = a & src;
}

void handle_bitwise_flags(const uint8_t result, const uint8_t value1, const uint8_t value2)
{
    handle_zero_flag(result);
    handle_sign_flag(result);
    handle_parity_flag(result);
    //handle_aux_carry_flag_add(value1, value2); // TODO: Figure out correct aux carry behavior
}
