//
// Created by Jake Kinsella on 6/16/17.
//

#include "opcode_definitions.h"
#include "opcodes/data_transfer.h"
#include "opcodes/arithmetic/add.h"
#include "opcodes/miscellaneous.h"
#include "opcodes/arithmetic/sub.h"
#include "opcodes/arithmetic/increment.h"
#include "opcodes/arithmetic/miscellaneous_arithmetic.h"
#include "opcodes/logical/bitwise.h"
#include "opcodes/logical/miscellaneous_logical.h"
#include "opcodes/branch/jump.h"
#include "opcodes/branch/call.h"
#include "opcodes/stack.h"

void define_data_transfer_opcodes();
void define_arithmetic_opcodes();
void define_logical_opcodes();
void define_branch_opcodes();
void define_miscellaneous_opcodes();

void define_opcodes()
{
    define_data_transfer_opcodes();
    define_arithmetic_opcodes();
    define_logical_opcodes();
    define_branch_opcodes();
    define_miscellaneous_opcodes();
}

void define_data_transfer_opcodes()
{
    InstructionTemplate move_register_template = new_instruction_template("01DDDSSS", &move_register);
    add_instruction_template(move_register_template);

    InstructionTemplate move_from_memory_template = new_instruction_template("01DDD110", &move_from_memory);
    add_instruction_template(move_from_memory_template);

    InstructionTemplate move_to_memory_template = new_instruction_template("01110SSS", &move_to_memory);
    add_instruction_template(move_to_memory_template);

    InstructionTemplate move_immediate_template = new_instruction_template("00DDD110", &move_immediate);
    add_instruction_template(move_immediate_template);

    InstructionTemplate move_to_memory_immediate_template = new_instruction_template("00110110", &move_to_memory_immediate);
    add_instruction_template(move_to_memory_immediate_template);

    InstructionTemplate load_register_pair_immediate_template = new_instruction_template("00RP0001", &load_register_pair_immediate);
    add_instruction_template(load_register_pair_immediate_template);

    InstructionTemplate load_accumulator_direct_template = new_instruction_template("00111010", &load_accumulator_direct);
    add_instruction_template(load_accumulator_direct_template);

    InstructionTemplate store_accumulator_direct_template = new_instruction_template("00110010", &store_accumulator_direct);
    add_instruction_template(store_accumulator_direct_template);

    InstructionTemplate load_HL_direct_template = new_instruction_template("00101010", &load_HL_direct);
    add_instruction_template(load_HL_direct_template);

    InstructionTemplate store_HL_direct_template = new_instruction_template("00100010", &store_HL_direct);
    add_instruction_template(store_HL_direct_template);

    InstructionTemplate load_accumulator_indirect_template = new_instruction_template("00RP1010", &load_accumulator_indirect);
    add_instruction_template(load_accumulator_indirect_template);

    InstructionTemplate store_accumulator_indirect_template = new_instruction_template("00RP0010", &store_accumulator_indirect);
    add_instruction_template(store_accumulator_indirect_template);

    InstructionTemplate exchange_HL_DE_template = new_instruction_template("11101011", &exchange_HL_DE);
    add_instruction_template(exchange_HL_DE_template);
}

void define_arithmetic_opcodes()
{
    // add
    InstructionTemplate add_register_template = new_instruction_template("10000SSS", &add_register);
    add_instruction_template(add_register_template);

    InstructionTemplate add_memory_template = new_instruction_template("10000110", &add_memory);
    add_instruction_template(add_memory_template);

    InstructionTemplate add_immediate_template = new_instruction_template("11000110", &add_immediate);
    add_instruction_template(add_immediate_template);

    InstructionTemplate add_register_with_carry_template = new_instruction_template("10001SSS", &add_register_with_carry);
    add_instruction_template(add_register_with_carry_template);

    InstructionTemplate add_memory_with_carry_template = new_instruction_template("10001110", &add_memory_with_carry);
    add_instruction_template(add_memory_with_carry_template);

    InstructionTemplate add_immediate_with_carry_template = new_instruction_template("11001110", &add_immediate_with_carry);
    add_instruction_template(add_immediate_with_carry_template);

    // sub
    InstructionTemplate sub_register_template = new_instruction_template("10010SSS", &sub_register);
    add_instruction_template(sub_register_template);

    InstructionTemplate sub_memory_template = new_instruction_template("10010110", &sub_memory);
    add_instruction_template(sub_memory_template);

    InstructionTemplate sub_immediate_template = new_instruction_template("11010110", &sub_immediate);
    add_instruction_template(sub_immediate_template);

    InstructionTemplate sub_register_with_borrow_template = new_instruction_template("10011SSS", &sub_register_with_borrow);
    add_instruction_template(sub_register_with_borrow_template);

    InstructionTemplate sub_memory_with_borrow_template = new_instruction_template("10011110", &sub_memory_with_borrow);
    add_instruction_template(sub_memory_with_borrow_template);

    InstructionTemplate sub_immediate_with_borrow_template = new_instruction_template("10011110", &sub_immediate_with_borrow);
    add_instruction_template(sub_immediate_with_borrow_template);

    // increment
    InstructionTemplate increment_register_template = new_instruction_template("00DDD100", &increment_register);
    add_instruction_template(increment_register_template);

    InstructionTemplate increment_memory_template = new_instruction_template("00110100", &increment_memory);
    add_instruction_template(increment_memory_template);

    InstructionTemplate decrement_register_template = new_instruction_template("00DDD101", &decrement_register);
    add_instruction_template(decrement_register_template);

    InstructionTemplate decrement_memory_template = new_instruction_template("00110101", &decrement_memory);
    add_instruction_template(decrement_memory_template);

    InstructionTemplate increment_register_pair_template = new_instruction_template("00RP0011", &increment_register_pair);
    add_instruction_template(increment_register_pair_template);

    InstructionTemplate decrement_register_pair_template = new_instruction_template("00RP1011", &decrement_register_pair);
    add_instruction_template(decrement_register_pair_template);

    InstructionTemplate add_register_pair_to_HL_template = new_instruction_template("00RP1001", &add_register_pair_to_HL);
    add_instruction_template(add_register_pair_to_HL_template);

    InstructionTemplate decimal_adjust_accumulator_template = new_instruction_template("00100111", &decimal_adjust_accumulator);
    add_instruction_template(decimal_adjust_accumulator_template);
}

void define_logical_opcodes()
{
    InstructionTemplate and_register_template = new_instruction_template("10100SSS", &and_register);
    add_instruction_template(and_register_template);

    InstructionTemplate and_memory_template = new_instruction_template("10100110", &and_memory);
    add_instruction_template(and_memory_template);

    InstructionTemplate and_immediate_template = new_instruction_template("11100110", &and_immediate);
    add_instruction_template(and_immediate_template);

    InstructionTemplate exclusive_or_register_template = new_instruction_template("10101SSS", &exclusive_or_register);
    add_instruction_template(exclusive_or_register_template);

    InstructionTemplate exclusive_or_memory_template = new_instruction_template("10101110", &exclusive_or_memory);
    add_instruction_template(exclusive_or_memory_template);

    InstructionTemplate exclusive_or_immediate_template = new_instruction_template("11101110", &exclusive_or_immediate);
    add_instruction_template(exclusive_or_immediate_template);

    InstructionTemplate or_register_template = new_instruction_template("10110SSS", &or_register);
    add_instruction_template(or_register_template);

    InstructionTemplate or_memory_template = new_instruction_template("10101110", &or_memory);
    add_instruction_template(or_memory_template);

    InstructionTemplate or_immediate_template = new_instruction_template("11101110", &or_immediate);
    add_instruction_template(or_immediate_template);

    InstructionTemplate compare_register_template = new_instruction_template("10111SSS", &compare_register);
    add_instruction_template(compare_register_template);

    InstructionTemplate compare_memory_template = new_instruction_template("10111110", &compare_memory);
    add_instruction_template(compare_memory_template);

    InstructionTemplate compare_immediate_template = new_instruction_template("11111110", &compare_immediate);
    add_instruction_template(compare_immediate_template);

    InstructionTemplate rotate_left_template = new_instruction_template("00000111", &rotate_left);
    add_instruction_template(rotate_left_template);

    InstructionTemplate rotate_right_template = new_instruction_template("00001111", &rotate_right);
    add_instruction_template(rotate_right_template);

    InstructionTemplate rotate_left_through_carry_template = new_instruction_template("00010111", &rotate_left_through_carry);
    add_instruction_template(rotate_left_through_carry_template);

    InstructionTemplate rotate_right_through_carry_template = new_instruction_template("00011111", &rotate_right_through_carry);
    add_instruction_template(rotate_right_through_carry_template);

    InstructionTemplate complement_accumulator_template = new_instruction_template("00101111", &complement_accumulator);
    add_instruction_template(complement_accumulator_template);

    InstructionTemplate complement_carry_template = new_instruction_template("00111111", &complement_carry);
    add_instruction_template(complement_carry_template);

    InstructionTemplate set_carry_template = new_instruction_template("00110111", &set_carry);
    add_instruction_template(set_carry_template);
}

void define_branch_opcodes()
{
    InstructionTemplate jump_template = new_instruction_template("11000011", &jump);
    add_instruction_template(jump_template);

    InstructionTemplate jump_condition_template = new_instruction_template("11CCC011", &jump_condition);
    add_instruction_template(jump_condition_template);

    InstructionTemplate call_template = new_instruction_template("11000011", &call);
    add_instruction_template(call_template);
}

void define_miscellaneous_opcodes()
{
    InstructionTemplate push_register_pair_template = new_instruction_template("11RP0101", &push_register_pair);
    add_instruction_template(push_register_pair_template);

    InstructionTemplate push_processor_status_word_template = new_instruction_template("11110101", &push_processor_status_word);
    add_instruction_template(push_processor_status_word_template);

    InstructionTemplate pop_register_pair_template = new_instruction_template("11RP0001", &pop_register_pair);
    add_instruction_template(pop_register_pair_template);

    InstructionTemplate nop_template = new_instruction_template("00000000", &nop);
    add_instruction_template(nop_template);
}
