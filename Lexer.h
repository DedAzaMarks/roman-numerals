//
// Created by Maxim Bordyugov on 18/06/2021.
//

#include <string>
#include <vector>
#include <iterator>

#include "Tokens.h"
#include "Convert.h"

using std::string;
using std::vector;

#ifndef ROMAN_NUMERALS_LEXER_H
#define ROMAN_NUMERALS_LEXER_H

class Lexer {
 private:
  string &str;

  static bool is_operator(char c);

 public:
  vector<Token> tokens;

  explicit Lexer(string &_str);

  bool generate_tokens();
};

#endif //ROMAN_NUMERALS_LEXER_H
