//
// Created by aiden on 2024-05-04.
//

#include <gtest/gtest.h>
#include "Brainfuck.h"

TEST(BrainfuckTests, IncrementData) {
    std::string instructions = "+";
    Brainfuck bf(instructions);
    bf.run();
    char data = bf.getData(0);
    EXPECT_EQ(data, 0x1);
}

TEST(BrainfuckTests, IncrementPointer) {
    std::string instructions = ">+";
    Brainfuck bf(instructions);
    bf.run();
    EXPECT_EQ(bf.getData(0), 0x0);
    EXPECT_EQ(bf.getData(1), 0x1);
}

TEST(BrainfuckTests, BasicLoop) {
    // increment data[0] to 2, enter loop
    // in loop: increment data[1] twice and decrement data[0]
    // final result: data[0] == 0, data[1] == 4
    std::string instructions = "++[>++<-]";
    Brainfuck bf(instructions);
    bf.run();
    EXPECT_EQ(bf.getData(0), 0x0);
    EXPECT_EQ(bf.getData(1), 0x4);
}