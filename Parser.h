//
// Created by Maxim Bordyugov on 18/06/2021.
//

#ifndef ROMAN_NUMERALS_PARSER_H
#define ROMAN_NUMERALS_PARSER_H

#include <vector>
#include <string>
#include <memory>

#include "Tokens.h"
#include "Node.h"

using std::string;
using std::vector;

class Parser {
  vector<Token>::iterator it, end;
 public:
  shared_ptr<Node> res;

  explicit Parser(vector<Token> &_tokens);

  void parse();

  shared_ptr<Node> expr();

  shared_ptr<Node> term();

  shared_ptr<Node> factor();
};

#endif //ROMAN_NUMERALS_PARSER_H
