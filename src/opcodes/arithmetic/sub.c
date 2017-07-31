//
// Created by Jake Kinsella on 6/30/17.
//

#include "sub.h"
#include "../../log.h"

void sub_8bit(uint8_t *dst, const uint8_t src);
void handle_flags_sub(const int final_value, const int value1, const int value2);

void sub_register(const uint8_t src_register)
{
    log("SUB r\n");

    int tmp = a;

    sub_8bit(&a, src_register);

    handle_flags_sub(a, tmp, src_register);
    pc++;
}

void sub_memory()
{
    log("SUB M\n");

    int tmp = a;
    uint8_t byte = read_byte(h, l);

    sub_8bit(&a, byte);

    handle_flags_sub(a, tmp, byte);
    pc++;
}

void sub_immediate()
{
    log("SUI data\n");

    int tmp = a;
    uint8_t byte = read_byte_from_address((uint16_t) (pc + 1));

    sub_8bit(&a, byte);

    handle_flags_sub(a, tmp, byte);
    pc += 2;
}

void sub_register_with_borrow(const uint8_t src_register)
{
    log("SBB r\n");

    int tmp = a;
    uint8_t byte = (uint8_t) (src_register + get_carry_flag());

    sub_8bit(&a, byte);

    handle_flags_sub(a, tmp, byte);
    pc++;
}

void sub_memory_with_borrow()
{
    log("SBB M\n");

    int tmp = a;
    uint8_t byte = (uint8_t) (read_byte(h, l) + get_carry_flag());

    sub_8bit(&a, byte);

    handle_flags_sub(a, tmp, byte);
    pc++;
}

void sub_immediate_with_borrow()
{
    log("SBI data\n");

    int tmp = a;
    uint8_t byte = (uint8_t) (read_byte_from_address((uint16_t) (pc + 1)) + get_carry_flag());

    sub_8bit(&a, byte);

    handle_flags_sub(a, tmp, byte);
    pc += 2;
}

void sub_8bit(uint8_t *dst, const uint8_t src)
{
    if ((*dst - src) < 0) {
        *dst = 0;
        return;
    }

    *dst -= src;
}

void handle_flags_sub(const int final_value, const int value1, const int value2)
{
    handle_zero_flag(final_value);
    handle_sign_flag(final_value);
    handle_carry_flag_sub(value1, value2);
    handle_aux_carry_flag_sub(value1, value2);
    handle_parity_flag(final_value);
}
