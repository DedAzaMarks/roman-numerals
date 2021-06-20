//
// Created by Maxim Bordyugov on 18/06/2021.
//

#include "Parser.h"
#include "Convert.h"

Parser::Parser(vector<Token> &_tokens) {
  it = _tokens.begin();
  end = _tokens.end();
}

bool Parser::parse() {
  if (it == end)
    return true;

  res = expr();

  if (it != end)
    return true;

  return false;
}

shared_ptr<Node> Parser::expr() {
  shared_ptr<Node> result = term();
  while (it != end && (it->TokenType == PLUS || it->TokenType == MINUS)) {
    if (it->TokenType == PLUS) {
      ++it;
      result = make_node(result, term(), '+');
    } else if (it->TokenType == MINUS) {
      ++it;
      result = make_node(result, term(), '-');
    }
  }
  return result;
}

shared_ptr<Node> Parser::term() {
  shared_ptr<Node> result = factor();
  while (it != end && (it->TokenType == MULTIPLY || it->TokenType == DIVIDE)) {
    if (it->TokenType == MULTIPLY) {
      ++it;
      result = make_node(result, factor(), '*');
    } else if (it->TokenType == DIVIDE) {
      ++it;
      result = make_node(result, factor(), '/');
    }
  }
  return result;
}

shared_ptr<Node> Parser::factor() {
  if (it->TokenType == LPAREN) {
    ++it;
    shared_ptr<Node> node = expr();
    if (it->TokenType != RPAREN)
      throw std::runtime_error("error: bad parenthesis\n");
    ++it;
    return node;
  } else if (it->TokenType == NUMBER) {
    shared_ptr<Node> number_node = make_node(Convert::to_int(it->value));
    ++it;
    return number_node;
  } else if (it->TokenType == MINUS) {
    ++it;
    shared_ptr<Node> number_node = make_node(make_node(-1), factor(), '*');
    return number_node;
  }
  throw std::runtime_error("error: wrong expression\n");
}