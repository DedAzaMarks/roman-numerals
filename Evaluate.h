//
// Created by Maxim Bordyugov on 18/06/2021.
//

#ifndef ROMAN_NUMERALS_EVALUATE_H
#define ROMAN_NUMERALS_EVALUATE_H

#include "Nodes.h"

int64_t evaluate(Node* node) {
    if (node->op == '\0')
        return node->value;
    else if (node->op == '+')
        return evaluate(node->l) + evaluate(node->r);
    else if (node->op == '-')
        return evaluate(node->l) - evaluate(node->r);
    else if (node->op == '*')
        return evaluate(node->l) * evaluate(node->r);
    else if (node->op == '/')
        return evaluate(node->l) / evaluate(node->r);
    return 0;
}

#endif //ROMAN_NUMERALS_EVALUATE_H
