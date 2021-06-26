cmake_minimum_required(VERSION 3.16)
project(roman_numerals)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Werror -Wall -Wextra -Wpedantic")

include_directories(.)

add_executable(roman_numerals
        main.cpp
        Convert.cpp
        Lexer.cpp
        Parser.cpp
        Node.cpp)
