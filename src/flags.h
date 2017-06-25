//
// Created by Jake Kinsella on 6/24/17.
//

#ifndef INC_8080_EMULATOR_FLAGS_H
#define INC_8080_EMULATOR_FLAGS_H

#include "registers.h"

void set_zero_flag(bool flag);
void set_sign_flag(bool flag);
void set_parity_flag(bool flag);
void set_carry_flag(bool flag);
void set_aux_carry_flag(bool flag);

void handle_zero_flag(const int value);
void handle_sign_flag(const int value);
void handle_parity_flag(const int value);
void handle_carry_flag_add(const int value1, const int value2);
void handle_carry_flag_sub(const int value1, const int value2)
void handle_aux_carry_flag(const int value);

#endif //INC_8080_EMULATOR_FLAGS_H
