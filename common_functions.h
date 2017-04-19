//
// Created by Jake Kinsella on 4/17/17.
//

#ifndef INC_8080_EMULATOR_COMMON_FUNCTIONS_H
#define INC_8080_EMULATOR_COMMON_FUNCTIONS_H

#include <stdint.h>

uint16_t combine_bytes(uint8_t high, uint8_t low);
int get_dst_code_from_opcode(int instruction);
int get_src_code_from_opcode(int instruction);
int get_rp_code_from_opcode(int instruction);

#endif //INC_8080_EMULATOR_COMMON_FUNCTIONS_H
