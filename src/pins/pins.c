//
// Created by Jake Kinsella on 7/26/17.
//

#include "pins.h"
#include "../registers.h"

void handle_reset_pin();

void initialize_pins()
{
    for (int i = 0; i < PIN_NUMBER; i++) {
        pins[i] = 0;
    }

    initialize_data_bus();
    initialize_address_bus();
}

void write_pin(int pin_index, bool value)
{
    pins[pin_index] = value;
}

bool read_pin(int pin_index)
{
    return pins[pin_index];
}

void handle_input_pins()
{
    handle_reset_pin();
}

void handle_reset_pin()
{
    if (pins[RESET]) {
        pc = 0;
    }
}
