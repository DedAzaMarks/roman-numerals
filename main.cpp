#include <iostream>
#include <string>
#include <vector>

#include "Convert.h"
#include "Lexer.h"
#include "Parser.h"

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::remove;
using std::to_string;

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
      long long int ans = tree->evaluate();
      cout << Convert::to_roman(ans) << "\n";
    } catch (const std::exception &e) {
      cout << e.what();
    }
  }
  return 0;
}