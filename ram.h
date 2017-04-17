//
// Created by Jake Kinsella on 4/17/17.
//

#ifndef INC_8080_EMULATOR_MEMORY_H
#define INC_8080_EMULATOR_MEMORY_H

#define BYTES_OF_RAM 64 * 1024

#include <stdint.h>

uint8_t ram[BYTES_OF_RAM];

void initialize_ram();
uint8_t get_byte(uint8_t high, uint8_t low);
uint8_t get_byte_from_address(uint16_t address);

#endif //INC_8080_EMULATOR_MEMORY_H
