//
// Created by Jake Kinsella on 7/20/17.
//

#include "miscellaneous_branch.h"
#include "../../log.h"

// Using condition int in place of NNN. Technically works the same
void restart(int condition)
{
    log("RST n\n");

    push(get_high_order_byte(pc));
    push(get_low_order_byte(pc));

    pc = (uint16_t) (8 * condition);
}

void jump_HL_indirect()
{
    log("PCHL\n");

    pc = combine_bytes(h, l);
}
