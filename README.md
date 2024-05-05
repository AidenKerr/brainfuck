# Brainfuck Interpreter

A brainfuck interpreter written in C++.

To use, just run the program with a path to your file as the argument.


| Instructions | Description                                               |
|--------------|-----------------------------------------------------------|
| +            | Increment the byte at the current data pointer position   |
| -            | Decrement the byte at the current data pointer position   |
| \>           | Increment data pointer                                    |
| <            | Decrement data pointer                                    |
| .            | Print byte at current data pointer                        |
| ,            | Accept 1 char of input and store at data pointer position |
| [            | If value at data pointer is 0, jump to matching ]         |
| ]            | If value at data pointer is not 0, jump to matching [     |

