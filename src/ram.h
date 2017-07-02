//
// Created by Jake Kinsella on 4/17/17.
//

#ifndef INC_8080_EMULATOR_MEMORY_H
#define INC_8080_EMULATOR_MEMORY_H

#define BYTES_OF_RAM 64 * 1024

#include <stdio.h>
#include <stdint.h>

uint8_t ram[BYTES_OF_RAM];

void initialize_ram();

uint8_t read_byte(uint8_t address_high, uint8_t address_low);
uint8_t read_byte_from_address(uint16_t address);
uint8_t * read_byte_pointer(uint8_t address_high, uint8_t address_low);

uint16_t read_16bits_from_address(uint16_t address);

void set_byte(uint8_t address_high, uint8_t address_low, uint8_t value);
void set_byte_from_address(uint16_t address, uint8_t value);

#endif //INC_8080_EMULATOR_MEMORY_H
