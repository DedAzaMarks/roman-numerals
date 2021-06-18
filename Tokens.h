//
// Created by Maxim Bordyugov on 18/06/2021.
//

#ifndef ROMAN_NUMERALS_TOKENS_H
#define ROMAN_NUMERALS_TOKENS_H

#include <string>

using std::string;

enum Type {
    NUMBER      = 0,
    PLUS        = 1,
    MINUS       = 2,
    MULTIPLY    = 3,
    DIVIDE      = 4,
    LPAREN      = 5,
    RPAREN      = 6
};

struct Token {
    Type TokenType;
    string value;
};

#endif //ROMAN_NUMERALS_TOKENS_H
