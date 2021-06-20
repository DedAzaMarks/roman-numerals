cmake_minimum_required(VERSION 3.19)
project(roman_numerals)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(roman_numerals
        main.cpp
        Convert.cpp
        Evaluate.cpp
        Lexer.cpp
        Parser.cpp
        Node.cpp)
