//
// Created by aiden on 2024-04-26.
//

#ifndef BRAINFUCK_BRAINFUCK_H
#define BRAINFUCK_BRAINFUCK_H

#include <string>
#include <map>

class Brainfuck {
public:
    explicit Brainfuck(std::string ins): instructions(std::move(ins)){
        preprocess();
    };
    void run();
    char getData(int index);
private:
    std::string instructions;
    std::map<int, int> jump_map;
    char data[3000] = {0};
    int i_ptr = 0; // instruction pointer
    int d_ptr = 0; // data pointer
    void process_instruction(char instruction);
    void preprocess();
};


#endif //BRAINFUCK_BRAINFUCK_H
