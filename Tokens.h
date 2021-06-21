//
// Created by Maxim Bordyugov on 18/06/2021.
//

#ifndef ROMAN_NUMERALS_TOKENS_H
#define ROMAN_NUMERALS_TOKENS_H

#include <string>

using std::string;

enum Type {
  NUMBER    = 1,
  PLUS      = 2,
  MINUS     = 3,
  MULTIPLY  = 4,
  DIVIDE    = 5,
  LPAREN    = 6,
  RPAREN    = 7
};

struct Token {
  Type TokenType;
  string value;
};

#endif //ROMAN_NUMERALS_TOKENS_H
