//
// Created by Jake Kinsella on 6/19/17.
//

#include <assert.h>
#include "../src/matcher/matcher.h"
#include "../src/registers.h"

void dst_run(uint8_t *dst_register);
void src_run(const uint8_t src_register);
void rp_run(RegisterPair *dst_register_pair);
void dst_src_run(uint8_t *dst_register, const uint8_t src_register);

int value_register1 = 0;
int value_register2 = 0;

int main(int argc, const char* argv[])
{

    return 0;
}

void dst_run(uint8_t *dst_register)
{
    value_register1 = *dst_register;
}

void src_run(const uint8_t src_register)
{
    value_register1 = src_register;
}

void rp_run(RegisterPair *dst_register_pair)
{
    value_register1 = combine_bytes(*dst_register_pair->register1, *dst_register_pair->register2);
}

void dst_src_run(uint8_t *dst_register, const uint8_t src_register)
{
    value_register1 = *dst_register;
    value_register2 = src_register;
}
