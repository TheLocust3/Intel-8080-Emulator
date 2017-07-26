//
// Created by Jake Kinsella on 7/23/17.
//

#ifndef INC_8080_EMULATOR_DATA_BUS_H
#define INC_8080_EMULATOR_DATA_BUS_H

#include <stdint.h>
#include "pins.h"
#include "../common_functions.h"

void initialize_data_bus();
void write_data_bus(uint8_t byte);
uint8_t read_data_bus();

#endif //INC_8080_EMULATOR_DATA_BUS_H
