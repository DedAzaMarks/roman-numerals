//
// Created by Maxim Bordyugov on 18/06/2021.
//

#include "Evaluate.h"

int64_t evaluate(const shared_ptr<Node> &node) {
  if (node->op == '\0')
    return node->value;
  else if (node->op == '+') {
    int64_t a = evaluate(node->l);
    int64_t b = evaluate(node->r);
    int64_t res;
    if (!__builtin_saddll_overflow(a, b, &res)) {
      return res;
    }
    throw std::overflow_error("error: signed 64-bits overflow\n");
  } else if (node->op == '-') {
    int64_t a = evaluate(node->l);
    int64_t b = evaluate(node->r);
    int64_t res;
    if (!__builtin_ssubll_overflow(a, b, &res)) {
      return res;
    }
    throw std::overflow_error("error: signed 64-bits overflow\n");
  } else if (node->op == '*') {
    int64_t a = evaluate(node->l);
    int64_t b = evaluate(node->r);
    int64_t res;
    if (!__builtin_smulll_overflow(a, b, &res)) {
      return res;
    }
    throw std::overflow_error("error: signed 64-bits overflow\n");
  } else if (node->op == '/') {
    int64_t a = evaluate(node->l);
    int64_t b = evaluate(node->r);
    if (b == 0) {
      throw std::runtime_error("error: division by zero\n");
    }
    int64_t res = a / b;
    return res;
  }
  return 0;
}