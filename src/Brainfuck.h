//
// Created by aiden on 2024-04-26.
//

#ifndef BRAINFUCK_BRAINFUCK_H
#define BRAINFUCK_BRAINFUCK_H

#include <string>
#include <vector>

class Brainfuck {
public:
    explicit Brainfuck(std::string ins): instructions(std::move(ins)){};
    std::string instructions;
    std::vector<int> stack;
    char data[3000] = {0};
    int i_ptr = 0; // instruction pointer
    int d_ptr = 0; // data pointer
    void run();
    char* getData(); // only used for testing
private:
    void process_instruction(char instruction);
};


#endif //BRAINFUCK_BRAINFUCK_H
