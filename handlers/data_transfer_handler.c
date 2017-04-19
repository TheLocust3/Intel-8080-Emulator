//
// Created by Jake Kinsella on 4/18/17.
//

#include "data_transfer_handler.h"
#include "../opcodes/data_transfer.h"
#include "../registers.h"
#include "../common_functions.h"

bool handle_MOV(uint8_t instruction);
bool handle_MVI(uint8_t instruction);

bool handle_data_transfer_instruction(uint8_t instruction)
{
    if (handle_MOV(instruction)) return true;
    if (handle_MVI(instruction)) return true;

    return false;
}

bool handle_MOV(uint8_t instruction)
{
    if (((instruction & 0b11000000) >> 6) == 0b01) {
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

bool handle_MVI(uint8_t instruction)
{
    if (((instruction & 0b11000000) >> 6) == 0b00 && (instruction & 0b00000111) == 0b110) {
        if ((instruction & 0b00111000) == 0b110) {
            printf("MVI M, data");
            move_to_memory_immediate();

            return true;
        }

        int dst_code = get_dst_code_from_opcode(instruction);
        uint8_t dst_register = get_register_from_code(dst_code);

        if (dst_register != NULL_REGISTER) {
            printf("MVI r, data\n");
            move_immediate(&dst_register);

            return true;
        }
    }

    return false;
}
