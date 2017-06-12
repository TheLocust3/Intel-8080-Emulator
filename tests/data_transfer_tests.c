//
// Created by Jake Kinsella on 6/10/17.
//

#include <stdio.h>
#include "../src/opcodes/data_transfer.h"
#include "../src/registers.h"

int move_register_test();

int main(int argc, const char* argv[])
{
    int status = move_register_test();
    return !status;
}

int move_register_test()
{
    a = 0;
    b = 10;
    move_register(&a, b);

    return a == b;
}