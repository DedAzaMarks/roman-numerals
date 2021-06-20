//
// Created by Maxim Bordyugov on 18/06/2021.
//
#include <iostream>
#include <memory>
#include <utility>

#ifndef ROMAN_NUMERALS_NODES_H
#define ROMAN_NUMERALS_NODES_H

using std::shared_ptr;

typedef struct Node {
  int64_t value;
  shared_ptr<Node> l;
  shared_ptr<Node> r;
  char op;
} Node;

shared_ptr<Node> make_node(shared_ptr<Node> l, shared_ptr<Node> r, char op);

shared_ptr<Node> make_node(int64_t val);

#endif //ROMAN_NUMERALS_NODES_H
