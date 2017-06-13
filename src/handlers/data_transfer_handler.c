//
// Created by Jake Kinsella on 4/18/17.
//

#include "data_transfer_handler.h"
#include "../opcodes/data_transfer.h"
#include "../registers.h"
#include "../common_functions.h"

bool handle_MOV(uint8_t instruction);
bool handle_MVI(uint8_t instruction);
bool handle_misc(uint8_t instruction);

bool handle_data_transfer_instruction(uint8_t instruction)
{
    if (handle_MOV(instruction)) return true;
    if (handle_MVI(instruction)) return true;
    if (handle_misc(instruction)) return true;

    return false;
}

bool handle_MOV(uint8_t instruction)
{
    if (((instruction & 0b11000000) >> 6) == 0b01) {
        int dst_code = get_dst_code_from_opcode(instruction);
        uint8_t dst_register = get_register_from_code(dst_code);

        int src_code = get_src_code_from_opcode(instruction);
        uint8_t src_register = get_register_from_code(src_code);

        if (is_code_8bit_code(dst_code) && is_code_8bit_code(src_code)) {
            move_register(&dst_register, src_register);
            return true;
        } else if (is_code_8bit_code(dst_code) && !is_code_8bit_code(src_code)) {
            move_from_memory(&dst_register);
            return true;
        } else if (!is_code_8bit_code(dst_code) && is_code_8bit_code(src_code)) {
            move_to_memory(src_register);
            return true;
        }
    }

    return false;
}

bool handle_MVI(uint8_t instruction)
{
    if (((instruction & 0b11000000) >> 6) == 0b00 && (instruction & 0b00000111) == 0b110) {
        if ((instruction & 0b00111000) >> 3 == 0b110) {
            move_to_memory_immediate();
            return true;
        }

        int dst_code = get_dst_code_from_opcode(instruction);

        if (is_code_8bit_code(dst_code)) {
            uint8_t dst_register = get_register_from_code(dst_code);
            move_immediate(&dst_register);
            return true;
        }
    }

    return false;
}

bool handle_misc(uint8_t instruction)
{
    if (instruction == 0b00111010) {
        load_accumulator_direct();
    }

    if (((instruction & 0b11000000) >> 6) == 0b00) {
        if ((instruction & 0b00001111) == 0b0001) {
            int rp_code = get_rp_code_from_opcode(instruction);

            if (is_code_16bit_code(rp_code)) {
                RegisterPair dst_register_pair = get_register_pair_from_code(rp_code);
                load_register_pair_immediate(&dst_register_pair);
            }
        }
    }
}
