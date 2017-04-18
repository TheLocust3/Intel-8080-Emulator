//
// Created by Jake Kinsella on 4/17/17.
//

#include "move.h"
#include "../registers.h"
#include "../ram.h"
#include "../common_functions.h"

void move_byte(uint8_t *dst, const uint8_t src);
void move_byte_to_memory(const uint8_t dst_address, const uint8_t src);

bool handle_move_instruction(uint8_t instruction)
{
    if (((instruction & 0b11000000) >> 6) == 0b01) { // move instruction
        int dst_code = get_dst_code_from_opcode(instruction);
        uint8_t dst_register = get_register_from_code(dst_code);

        int src_code = get_src_code_from_opcode(instruction);
        uint8_t src_register = get_register_from_code(src_code);

        if (dst_register != NULL_REGISTER && src_register != NULL_REGISTER) {
            printf("MOV r1, r2\n");
            move_register(&dst_register, src_register);

            return true;
        } else if (dst_register != NULL_REGISTER && src_register == NULL_REGISTER) {
            printf("MOV r, M\n");
            move_from_memory(&dst_register);

            return true;
        } else if (dst_register == NULL_REGISTER && src_register != NULL_REGISTER) {
            printf("MOV M, r\n");
            move_to_memory(src_register);

            return true;
        }
    }

    return false;
}

void move_register(uint8_t *dst_register, const uint8_t src_register)
{
    move_byte(dst_register, src_register);
    pc++;
}

void move_from_memory(uint8_t *dst_register)
{
    move_byte(dst_register, read_byte(h, l));
    pc++;
}

void move_to_memory(const uint8_t src_register)
{
    move_byte_to_memory(read_byte(h, l), src_register);
    pc++;
}

void move_byte(uint8_t *dst, const uint8_t src)
{
    *dst = src;
}

void move_byte_to_memory(const uint8_t dst_address, const uint8_t src)
{
    set_byte_from_address(dst_address, src);
}