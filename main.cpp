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

bool is_operator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

void print(Node* node) {
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

void clear(Node *node) {
    if (node == nullptr)
        return;
    clear(node->l);
    clear(node->r);
    delete node;
}

int main() {
    string str = "";
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
                continue;;
            }
            Node* tree = parser.res;
            print(tree); cout << " = " << evaluate(tree) << " " << Convert::to_roman(evaluate(tree)) << "\n";
            clear(tree);
        } catch (const std::exception& e) {
            cout << e.what();
        }
    }
    return 0;
}