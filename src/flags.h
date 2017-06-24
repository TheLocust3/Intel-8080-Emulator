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

#endif //INC_8080_EMULATOR_FLAGS_H
