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
    try {
      Lexer lexer(str);
      lexer.generate_tokens();

      Parser parser(lexer.tokens);
      parser.parse();

      shared_ptr<Node> tree = parser.res;
      long long int ans = tree->evaluate();
      cout << Convert::to_roman(ans) << "\n";
    } catch (const std::exception &e) {
      cout << e.what();
    }
  }
  return 0;
}
