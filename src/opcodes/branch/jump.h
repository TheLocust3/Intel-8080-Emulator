//
// Created by Jake Kinsella on 7/11/17.
//

#ifndef INC_8080_EMULATOR_JUMP_H
#define INC_8080_EMULATOR_JUMP_H

#include "../../registers.h"
#include "../../ram.h"
#include "../../common_functions.h"

#define CONDITIONAL_NZ 0b000
#define CONDITIONAL_Z0b001
#define CONDITIONAL_NC 0b010
#define CONDITIONAL_C 0b011
#define CONDITIONAL_PO 0b100
#define CONDITIONAL_PE 0b101
#define CONDITIONAL_P 0b110
#define CONDITIONAL_M 0b111

void jump();

#endif //INC_8080_EMULATOR_JUMP_H
