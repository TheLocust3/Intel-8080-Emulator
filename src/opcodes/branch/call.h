//
// Created by Jake Kinsella on 7/14/17.
//

#ifndef INC_8080_EMULATOR_CALL_H
#define INC_8080_EMULATOR_CALL_H

#include "../../registers.h"
#include "../../ram.h"
#include "../../common_functions.h"
#include "../stack.h"
#include "jump.h"
#include "../../flags.h"

void call();
void call_condition(int condition);
void return_plain();
void return_condition(int condition);

#endif //INC_8080_EMULATOR_CALL_H
