//
// Created by Jake Kinsella on 7/23/17.
//

#ifndef INC_8080_EMULATOR_DATA_BUS_H
#define INC_8080_EMULATOR_DATA_BUS_H

#include <stdint.h>

uint8_t bus;

void initialize_bus();
void write_bus(uint8_t byte);
uint8_t read_bus();

#endif //INC_8080_EMULATOR_DATA_BUS_H
