//
// Created by Maxim Bordyugov on 18/06/2021.
//
#include <iostream>
#include <memory>
#include <utility>

#ifndef ROMAN_NUMERALS_NODES_H
#define ROMAN_NUMERALS_NODES_H

using std::shared_ptr;

class Node {
 public:
  virtual long long int evaluate() = 0;
  virtual void print() = 0;
};

class NumberNode : public Node {
 private:
  long long int val;
 public:
  explicit NumberNode(long long int);
  long long int evaluate() override;
  void print() override;
};

class MinusNode : public Node {
 private:
  shared_ptr<Node> node;
 public:
  explicit MinusNode(shared_ptr<Node>);
  long long int evaluate() override;
  void print() override;
};

class AddNode : public Node {
 private:
  shared_ptr<Node> l, r;
 public:
  AddNode(shared_ptr<Node>, shared_ptr<Node>);
  long long int evaluate() override;
  void print() override;
};

class SubNode : public Node {
 private:
  shared_ptr<Node> l, r;
 public:
  SubNode(shared_ptr<Node>, shared_ptr<Node>);
  long long int evaluate() override;
  void print() override;
};

class MulNide : public Node {
 private:
  shared_ptr<Node> l, r;
 public:
  MulNide(shared_ptr<Node>, shared_ptr<Node>);
  long long int evaluate() override;
  void print() override;
};

class DivNode : public Node {
 private:
  shared_ptr<Node> l, r;
 public:
  DivNode(shared_ptr<Node>, shared_ptr<Node>);
  long long int evaluate() override;
  void print() override;
};

#endif //ROMAN_NUMERALS_NODES_H
