cmake_minimum_required(VERSION 3.24)
project(brainfuck)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/2d16ed055d09c3689d44b272adc097393de948a0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(brainfuck src/main.cpp src/Brainfuck.cpp src/Brainfuck.h)
add_executable(unit_tests test/unit_tests.cpp src/Brainfuck.cpp src/Brainfuck.h)

target_link_libraries(unit_tests PUBLIC GTest::gtest_main GTest::gmock_main)
target_include_directories(unit_tests PUBLIC src)