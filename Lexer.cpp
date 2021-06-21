//
// Created by Maxim Bordyugov on 18/06/2021.
//

#include "Lexer.h"

bool Lexer::is_operator(char c) {
  if (c == '+' || c == '-' || c == '*' || c == '/')
    return true;
  return false;
}

Lexer::Lexer(string &_str) : str(_str) {}

void Lexer::generate_tokens() {
  for (size_t i = 0; i < str.length(); ++i) {
    if (str[i] == '(') {
      tokens.push_back({LPAREN, ""});
    } else if (str[i] == ')') {
      tokens.push_back({RPAREN, ""});
    } else if (str[i] == '+') {
      tokens.push_back({PLUS, ""});
    } else if (str[i] == '-') {
      tokens.push_back({MINUS, ""});
    } else if (str[i] == '*') {
      tokens.push_back({MULTIPLY, ""});
    } else if (str[i] == '/') {
      tokens.push_back({DIVIDE, ""});
    } else if (str[i] != ' ') {
      string tmp;
      auto j = i;
      while (str[j] != '(' && str[j] != ')' &&
          !is_operator(str[j]) && str[j] != ' ' && j != str.length()) {
        if (Convert::symbol(str[j]) == -1) {
          tokens.clear();
          throw std::runtime_error("error: wrong expression\n");
        }
        tmp += str[j];
        ++j;
      }
      i = j - 1;
      tokens.push_back({NUMBER, tmp});
    }
  }
}