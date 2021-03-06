//
// Created by Jake Kinsella on 7/5/17.
//

#include "bitwise.h"
#include "../../ram.h"
#include "../../log.h"

void handle_bitwise_flags(const uint8_t result, const uint8_t value1, const uint8_t value2);

void and(const uint8_t src);
void exclusive_or(const uint8_t src);
void or(const uint8_t src);

void and_register(const uint8_t src_register)
{
    log("ANA r\n");

    const uint8_t tmp = a;

    and(src_register);

    handle_bitwise_flags(a, tmp, src_register);
    set_carry_flag(false);

    pc++;
}

void and_memory()
{
    log("ANA (HL)\n");

    const uint8_t tmp = a;
    const uint8_t data = read_byte(h, l);

    and(data);

    handle_bitwise_flags(a, tmp, data);
    set_carry_flag(false);

    pc++;
}

void and_immediate()
{
    log("ANA data\n");

    const uint8_t tmp = a;
    const uint8_t data = read_byte_from_address(pc);

    and(data);

    handle_bitwise_flags(a, tmp, data);
    set_carry_flag(false);
    set_aux_carry_flag(false);

    pc += 2;
}

void exclusive_or_register(const uint8_t src_register)
{
    log("XRA r\n");

    const uint8_t tmp = a;

    exclusive_or(src_register);

    handle_bitwise_flags(a, tmp, src_register);
    set_carry_flag(false);
    set_aux_carry_flag(false);

    pc++;
}

void exclusive_or_memory()
{
    log("XRA (HL)\n");

    const uint8_t tmp = a;
    const uint8_t data = read_byte(h, l);

    exclusive_or(data);

    handle_bitwise_flags(a, tmp, data);
    set_carry_flag(false);
    set_aux_carry_flag(false);

    pc++;
}

void exclusive_or_immediate()
{
    log("XRI data\n");

    const uint8_t tmp = a;
    const uint8_t data = read_byte_from_address(pc);

    exclusive_or(data);

    handle_bitwise_flags(a, tmp, data);
    set_carry_flag(false);
    set_aux_carry_flag(false);

    pc += 2;
}

void or_register(const uint8_t src_register)
{
    log("ORA r\n");

    const uint8_t tmp = a;

    or(src_register);

    handle_bitwise_flags(a, tmp, src_register);
    set_carry_flag(false);
    set_aux_carry_flag(false);

    pc++;
}

void or_memory()
{
    log("ORA M\n");

    const uint8_t tmp = a;
    const uint8_t data = read_byte(h, l);

    or(data);

    handle_bitwise_flags(a, tmp, data);
    set_carry_flag(false);
    set_aux_carry_flag(false);

    pc++;
}

void or_immediate()
{
    log("ORI data\n");

    const uint8_t tmp = a;
    const uint8_t data = read_byte_from_address(pc);

    or(data);

    handle_bitwise_flags(a, tmp, data);
    set_carry_flag(false);
    set_aux_carry_flag(false);

    pc += 2;
}

void rotate_left()
{
    log("RLC\n");

    if ((a << 1) > 0xFF) {
        set_carry_flag(true);
    } else {
        set_carry_flag(false);
    }

    a = (uint8_t) (0xFF & (a << 1));

    pc++;
}

void rotate_right()
{
    log("RRC\n");

    if ((a >> 1) < 0) { // Might not properly catch it
        set_carry_flag(true);
    } else {
        set_carry_flag(false);
    }

    a = (uint8_t) (a >> 1);

    pc++;
}

void rotate_left_through_carry()
{
    log("RAL\n");

    int old_carry_flag = get_carry_flag();

    if ((a << 1) > 0xFF) {
        set_carry_flag(true);
    } else {
        set_carry_flag(false);
    }

    a = (uint8_t) ((0xFF & (a << 1)) + old_carry_flag);

    pc++;
}

void rotate_right_through_carry()
{
    log("RAR\n");

    int old_carry_flag = get_carry_flag() << 7;

    if ((a >> 1) < 0) { // Might not properly catch it
        set_carry_flag(true);
    } else {
        set_carry_flag(false);
    }

    a = (uint8_t) ((a >> 1) + old_carry_flag);

    pc++;
}

void and(const uint8_t src)
{
    a = a & src;
}

void exclusive_or(const uint8_t src)
{
    a = a ^ src;
}

void or(const uint8_t src)
{
    a = a | src;
}

void handle_bitwise_flags(const uint8_t result, const uint8_t value1, const uint8_t value2)
{
    handle_zero_flag(result);
    handle_sign_flag(result);
    handle_parity_flag(result);
    //handle_aux_carry_flag_add(value1, value2); // TODO: Figure out correct aux carry behavior
}
