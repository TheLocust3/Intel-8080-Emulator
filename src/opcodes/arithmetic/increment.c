//
// Created by Jake Kinsella on 7/2/17.
//

#include "increment.h"
#include "../../registers.h"

void handle_flags_increment(const int final_value, const int value1);
void handle_flags_decrement(const int final_value, const int value1);

void increment_8bit(uint8_t *dst);
void decrement_8bit(uint8_t *dst);

void increment_register(uint8_t *dst)
{
    printf("INR r\n");

    int tmp = a;

    increment_8bit(dst);

    handle_flags_increment(*dst, tmp);

    pc++;
}

void increment_memory()
{
    printf("INR M\n");

    int tmp = read_byte(h, l);
    uint8_t *memory = read_byte_pointer(h, l);

    increment_8bit(memory);

    handle_flags_increment(*memory, tmp);

    pc++;
}

void increment_register_pair(const RegisterPair dst_register_pair)
{
    printf("INX rp\n");

    int tmp = combine_bytes(*dst_register_pair.high, *dst_register_pair.low) + 1;
    if (tmp > 0xFFFF) {
        tmp = 0xFFFF;
    }

    *dst_register_pair.high = get_high_order_byte((uint16_t) tmp);
    *dst_register_pair.low = get_low_order_byte((uint16_t) tmp);

    pc++;
}

void decrement_register(uint8_t *dst)
{
    printf("DCR r\n");

    int tmp = a;

    decrement_8bit(dst);

    handle_flags_decrement(*dst, tmp);

    pc++;
}

void decrement_memory()
{
    printf("DCR M\n");

    int tmp = read_byte(h, l);
    uint8_t *memory = read_byte_pointer(h, l);

    decrement_8bit(memory);

    handle_flags_decrement(*memory, tmp);

    pc++;
}

void increment_8bit(uint8_t *dst)
{
    if ((*dst + 1) > 0xFF) {
        *dst = 0xFF;
        return;
    }

    *dst += 1;
}

void decrement_8bit(uint8_t *dst)
{
    if ((*dst + 1) > 0xFF) {
        *dst = 0xFF;
        return;
    }

    *dst -= 1;
}

void handle_flags_increment(const int final_value, const int value1)
{
    handle_zero_flag(final_value);
    handle_sign_flag(final_value);
    handle_aux_carry_flag_add(value1, 1);
    handle_parity_flag(a);
}

void handle_flags_decrement(const int final_value, const int value1)
{
    handle_zero_flag(final_value);
    handle_sign_flag(final_value);
    handle_aux_carry_flag_sub(value1, 1);
    handle_parity_flag(a);
}
