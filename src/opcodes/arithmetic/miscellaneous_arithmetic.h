//
// Created by Jake Kinsella on 7/4/17.
//

#ifndef INC_8080_EMULATOR_MISCELLANEOUS_ARITHMETIC_H
#define INC_8080_EMULATOR_MISCELLANEOUS_ARITHMETIC_H

#include "../../registers.h"
#include "../../common_functions.h"
#include "../../flags.h"

void add_register_pair_to_HL(const RegisterPair dst_register_pair);

#endif //INC_8080_EMULATOR_MISCELLANEOUS_ARITHMETIC_H
