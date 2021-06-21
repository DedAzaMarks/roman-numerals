//
// Created by Maxim Bordyugov on 18/06/2021.
//

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
  while (it != end && (it->TokenType == PLUS || it->TokenType == MINUS)) {
    if (it->TokenType == PLUS) {
      ++it;
      result = make_shared<AddNode>(result, term());
    } else if (it->TokenType == MINUS) {
      ++it;
      result = make_shared<SubNode>(result, term());
    }
  }
  return result;
}

shared_ptr<Node> Parser::term() {
  shared_ptr<Node> result = factor();
  while (it != end && (it->TokenType == MULTIPLY || it->TokenType == DIVIDE)) {
    if (it->TokenType == MULTIPLY) {
      ++it;
      result = make_shared<MulNode>(result, factor());
    } else if (it->TokenType == DIVIDE) {
      ++it;
      result = make_shared<DivNode>(result, factor());
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
    shared_ptr<NumberNode> number_node = make_shared<NumberNode>(Convert::to_int(it->value));
    ++it;
    return number_node;
  } else if (it->TokenType == MINUS) {
    ++it;
    shared_ptr<MinusNode> minus_node = make_shared<MinusNode>(factor());
    return minus_node;
  }
  throw std::runtime_error("error: wrong expression\n");
}