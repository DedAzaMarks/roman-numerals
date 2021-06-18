//
// Created by Maxim Bordyugov on 18/06/2021.
//
#include <iostream>
#ifndef ROMAN_NUMERALS_NODES_H
#define ROMAN_NUMERALS_NODES_H

typedef struct Node {
    int64_t value;
    struct Node* l;
    struct Node* r;
    char op;
} Node;

Node* make_node(Node* l, Node*r, char op) {
    Node *node = new Node;
    node->value = 0;
    node->l = l;
    node->r = r;
    node->op = op;
    return node;
}

Node* make_node(int64_t val) {
    Node* node = new Node;
    node->value = val;
    node->l = node->r = nullptr;
    node->op = '\0';
    return node;
}

#endif //ROMAN_NUMERALS_NODES_H
