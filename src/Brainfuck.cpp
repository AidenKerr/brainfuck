//
// Created by aiden on 2024-04-26.
//

#include <iostream>
#include "Brainfuck.h"

void Brainfuck::run() {
    while (i_ptr < instructions.length()) {
        char instruction = instructions[i_ptr];
        process_instruction(instruction);
    }
}

void Brainfuck::process_instruction(char instruction) {
    switch (instruction) {
        case '>':
            d_ptr++;
            break;
        case '<':
            d_ptr--;
            break;
        case '+':
            data[d_ptr]++;
            break;
        case '-':
            data[d_ptr]--;
            break;
        case '.':
            std::cout << data[d_ptr];
            break;
        case ',':
            std::cin >> data[d_ptr];
            break;
        case '[':
            if (data[d_ptr] == 0) {
                // jump to the matching ]
                std::vector<int> jump_stack;
                jump_stack.push_back(i_ptr);
                while (!jump_stack.empty()) {
                    i_ptr++;
                    if (instructions[i_ptr] == '[')
                        jump_stack.push_back(i_ptr);
                    if (instructions[i_ptr] == ']')
                        jump_stack.pop_back();
                }
            } else {
                stack.push_back(i_ptr);
            }
            break;
        case ']':
            if (data[d_ptr] != 0) {
                i_ptr = stack.back();
            } else {
                stack.pop_back();
            }
            break;
        default: // other characters are treated as comments
            break;
    }
    i_ptr++;
}

char Brainfuck::getData(int index) {
    return data[index];
}
