//
// Created by Jake Kinsella on 7/26/17.
//

#ifndef INC_8080_EMULATOR_PINS_H
#define INC_8080_EMULATOR_PINS_H

#include <stdbool.h>
#include "data_bus.h"
#include "address_bus.h"

#define PIN_NUMBER 40

#define A10 1
#define GND 2
#define D4 3
#define D5 4
#define D6 5
#define D7 6
#define D3 7
#define D2 8
#define D1 9
#define D0 10
#define FIVE_V1 11
#define RESET 12
#define HOLD 13
#define INT 14
#define PHI_2 15
#define INTE 16
#define DBIN 17
#define WR 18
#define SYNC 19
#define FIVE_V2 0
#define HLDA 21
#define PHI_1 22
#define READY 23
#define WAIT 24
#define A0 25
#define A1 26
#define A2 27
#define TWELVE_V 28
#define A3 29
#define A4 30
#define A5 31
#define A6 32
#define A7 33
#define A8 34
#define A9 35
#define A15 36
#define A12 37
#define A13 38
#define A14 39
#define A11 40

bool pins[PIN_NUMBER];

void initialize_pins();
void write_pin(int pin_index, bool value);
bool read_pin(int pin_index);
void handle_input_pins();

#endif //INC_8080_EMULATOR_PINS_H
