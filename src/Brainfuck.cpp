//
// Created by aiden on 2024-04-26.
//

#include <iostream>
#include <stack>
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
                i_ptr = jump_map[i_ptr];
            }
            break;
        case ']':
            if (data[d_ptr] != 0) {
                i_ptr = jump_map[i_ptr];
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

void Brainfuck::preprocess() {
    std::stack<int> stack;
    for (int i = 0; i < instructions.length(); i++) {
        char c = instructions[i];
        if (c == '[') {
            stack.push(i);
        } else if (c == ']') {
            int start = stack.top();
            stack.pop();
            jump_map[start] = i;
            jump_map[i] = start;
        }
    }
}
