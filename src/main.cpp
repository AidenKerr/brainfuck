#include <fstream>
#include <sstream>
#include "Brainfuck.h"

int main(int argc, char *argv[]) {
    // default instructions if unspecified:
    std::string instructions = ">++++++++[-<+++++++++>]<.>>+>-[+]++>++>+++[>[->+++<<+++>]<<]>-----.>->+++..+++.>-.<<+[>[+>+]>>]<--------------.>>.+++.------.--------.>+.>+.";

    if (argc > 1) {
        std::ifstream file_stream(argv[1]);
        std::stringstream instruction_buffer;
        instruction_buffer << file_stream.rdbuf();
        instructions = instruction_buffer.str();
    }

    Brainfuck bf(instructions);
    bf.run();

    return 0;
}
