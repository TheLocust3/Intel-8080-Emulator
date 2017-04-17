//
// Created by Jake Kinsella on 4/17/17.
//

#ifndef INC_8080_EMULATOR_MOVE_H
#define INC_8080_EMULATOR_MOVE_H

#include <stdint.h>

void move_register(uint8_t *dst_register, uint8_t *src_register);
void move_from_memory(uint8_t *dst_register);
void move_to_memory(const uint8_t src_register);

#endif //INC_8080_EMULATOR_MOVE_H
