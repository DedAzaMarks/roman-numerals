//
// Created by Maxim Bordyugov on 18/06/2021.
//

#include "Node.h"

shared_ptr<Node> make_node(shared_ptr<Node> l, shared_ptr<Node> r, char op) {
  shared_ptr<Node> node = std::make_shared<Node>();
  node->value = 0;
  node->l = std::move(l);
  node->r = std::move(r);
  node->op = op;
  return node;
}

shared_ptr<Node> make_node(int64_t val) {
  shared_ptr<Node> node = std::make_shared<Node>();
  node->value = val;
  node->l = node->r = nullptr;
  node->op = '\0';
  return node;
}