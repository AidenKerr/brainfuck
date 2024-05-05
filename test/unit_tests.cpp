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

TEST(BrainfuckTests, ComplexLoop) {
    /*
     * Testing nested loops where an inner loop doesn't run on every loop
     * On each iteration, increment d[3]
     * Also, alternate between incrementing d[4] and d[5]
     * This can actually be used to check if n is even or odd, too! :)
     *
     * In the commented code, n=5. The actual test uses a different n
     *
     *  +++++>>+<<          initialize memory | 0: 5 | 1: 0 | 2: 1
     *  [>                  outer loop (point to d[1])
     *      [               if d(1) != 0
     *          [-]>[-]     reset to 1: 0 | 2: 0
     *          >>+         increment d(4)
     *          <<<         point to d(1)
     *      ]
     *      >[              else (when d(1) was 0 before)
     *          <+          set d(1) to 1
     *          >>>>+       increment d(5)
     *          <<<-        point to d(2) (and decrement it to escape)
     *      ]
     *      [-]+            reset d(2) to 1
     *      >+<<            increment d(3)
     *  <-]                 end outer loop (decrement counter)
     *
     */
    std::string instructions = "+++++++>>+<<[>[[-]>[-]>>+<<<]>[<+>>>>+<<<-][-]+>+<<<-]";
    Brainfuck bf(instructions);
    bf.run();
    EXPECT_EQ(bf.getData(0), 0x0);
    EXPECT_EQ(bf.getData(3), 0x7);
    EXPECT_EQ(bf.getData(4), 0x3);
    EXPECT_EQ(bf.getData(5), 0x4);
}