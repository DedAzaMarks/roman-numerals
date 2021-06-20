#include <iostream>
#include <string>
#include <vector>

#include "Convert.h"
#include "Lexer.h"
#include "Parser.h"
#include "Evaluate.h"

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::remove;
using std::to_string;

void print(const shared_ptr<Node> &node) {
  if (node == nullptr) {
    return;
  }
  cout << "(";
  print(node->l);
  if (node->op != '\0')
    cout << node->op;
  else
    cout << node->value;
  print(node->r);
  cout << ")";
}

int main() {
  string str;
  while (getline(cin, str)) {
    Lexer lexer(str);
    if (lexer.generate_tokens()) {
      cout << "error: wrong input\n";
      continue;
    }
    Parser parser(lexer.tokens);
    try {
      if (parser.parse()) {
        cout << "error: wrong expression\n";
        continue;
      }
      shared_ptr<Node> tree = parser.res;
      int64_t ans = evaluate(tree);
      cout << Convert::to_roman(ans) << "\n";
    } catch (const std::exception &e) {
      cout << e.what();
    }
  }
  return 0;
}