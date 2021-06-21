//
// Created by Maxim Bordyugov on 18/06/2021.
//

#include <stdexcept>

#include "Parser.h"
#include "Convert.h"

using std::make_shared;

Parser::Parser(vector<Token> &_tokens) {
  it = _tokens.begin();
  end = _tokens.end();
}

void Parser::parse() {
  if (it == end)
    throw std::runtime_error("error: wrong expression\n");

  res = expr();

  if (it != end)
    throw std::runtime_error("error: wrong expression\n");
}

shared_ptr<Node> Parser::expr() {
  shared_ptr<Node> result = term();
  while (it != end && (it->TokenType == Type::PLUS || it->TokenType == Type::MINUS)) {
    if (it->TokenType == Type::PLUS) {
      ++it;
      result = make_shared<AddNode>(result, term());
    } else if (it->TokenType == Type::MINUS) {
      ++it;
      result = make_shared<SubNode>(result, term());
    }
  }
  return result;
}

shared_ptr<Node> Parser::term() {
  shared_ptr<Node> result = factor();
  while (it != end && (it->TokenType == Type::MULTIPLY || it->TokenType == Type::DIVIDE)) {
    if (it->TokenType == Type::MULTIPLY) {
      ++it;
      result = make_shared<MulNode>(result, factor());
    } else if (it->TokenType == Type::DIVIDE) {
      ++it;
      result = make_shared<DivNode>(result, factor());
    }
  }
  return result;
}

shared_ptr<Node> Parser::factor() {
  if (it->TokenType == Type::LPAREN) {
    ++it;
    shared_ptr<Node> node = expr();
    if (it->TokenType != Type::RPAREN)
      throw std::runtime_error("error: bad parenthesis\n");
    ++it;
    return node;
  } else if (it->TokenType == Type::NUMBER) {
    shared_ptr<NumberNode> number_node = make_shared<NumberNode>(Convert::to_int(it->value));
    ++it;
    return number_node;
  } else if (it->TokenType == Type::MINUS) {
    ++it;
    shared_ptr<MinusNode> minus_node = make_shared<MinusNode>(factor());
    return minus_node;
  }
  throw std::runtime_error("error: wrong expression\n");
}
