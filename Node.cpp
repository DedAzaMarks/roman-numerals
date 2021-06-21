//
// Created by Maxim Bordyugov on 18/06/2021.
//

#include "Node.h"

#include <iostream>
#include <utility>

using std::cout;

NumberNode::NumberNode(long long int v) {
  val = v;
}

long long int NumberNode::evaluate() {
  return val;
}
void NumberNode::print() {
  cout << val;
}

MinusNode::MinusNode(shared_ptr<Node> n) {
  node = std::move(n);
}

long long int MinusNode::evaluate() {
  return -node->evaluate();
}
void MinusNode::print() {
  node->print();
}

AddNode::AddNode(shared_ptr<Node> left, shared_ptr<Node> right) {
  l = std::move(left);
  r = std::move(right);
}

long long int AddNode::evaluate() {
  long long int a = l->evaluate();
  long long int b = r->evaluate();
  long long int res;
  if (!__builtin_saddll_overflow(a, b, &res)) {
    return res;
  }
  throw std::overflow_error("error: signed 64-bits overflow\n");
}
void AddNode::print() {
  cout << "(";
  l->print();
  cout << "+";
  r->print();
  cout << ")";
}

SubNode::SubNode(shared_ptr<Node> left, shared_ptr<Node> right) {
  l = std::move(left);
  r = std::move(right);
}

long long int SubNode::evaluate() {
  long long int a = l->evaluate();
  long long int b = r->evaluate();
  long long int res;
  if (!__builtin_ssubll_overflow(a, b, &res)) {
    return res;
  }
  throw std::overflow_error("error: signed 64-bits overflow\n");
}
void SubNode::print() {
  cout << "(";
  l->print();
  cout << "-";
  r->print();
  cout << ")";
}

MulNode::MulNode(shared_ptr<Node> left, shared_ptr<Node> right) {
  l = std::move(left);
  r = std::move(right);
}

long long int MulNode::evaluate() {
  long long int a = l->evaluate();
  long long int b = r->evaluate();
  long long int res;
  if (!__builtin_smulll_overflow(a, b, &res)) {
    return res;
  }
  throw std::overflow_error("error: signed 64-bits overflow\n");
}
void MulNode::print() {
  cout << "(";
  l->print();
  cout << "*";
  r->print();
  cout << ")";
}

DivNode::DivNode(shared_ptr<Node> left, shared_ptr<Node> right) {
  l = std::move(left);
  r = std::move(right);
}

long long int DivNode::evaluate() {
  long long int a = l->evaluate();
  long long int b = r->evaluate();
  if (b == 0) {
    throw std::runtime_error("error: division by zero\n");
  }
  long long int res = a / b;
  return res;
}

void DivNode::print() {
  cout << "(";
  l->print();
  cout << "/";
  r->print();
  cout << ")";
}
