//
// Created by Jake Kinsella on 7/24/17.
//

#ifndef INC_8080_EMULATOR_ADDRESS_BUS_H
#define INC_8080_EMULATOR_ADDRESS_BUS_H

#include <stdint.h>

uint16_t address_bus;

void initialize_address_bus();
void write_address_bus(uint16_t byte);
uint16_t read_address_bus();

#endif //INC_8080_EMULATOR_ADDRESS_BUS_H
