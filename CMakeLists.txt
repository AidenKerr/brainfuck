cmake_minimum_required(VERSION 3.24)
project(brainfuck)

set(CMAKE_CXX_STANDARD 23)

add_executable(brainfuck src/main.cpp src/Brainfuck.cpp src/Brainfuck.h)
