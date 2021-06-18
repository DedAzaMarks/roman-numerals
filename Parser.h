//
// Created by Maxim Bordyugov on 18/06/2021.
//

#ifndef ROMAN_NUMERALS_PARSER_H
#define ROMAN_NUMERALS_PARSER_H

#include <vector>
#include <string>

#include "Tokens.h"
#include "Nodes.h"

using std::string;
using std::vector;

class Parser {
    vector<Token>::iterator begin, it, end;
public:
    Node *res;

    explicit Parser(vector<Token> &_tokens) {
        begin = it = _tokens.begin();
        end = _tokens.end();
    }

    bool parse() {
        if (it == end)
            return true;

        res = expr();

        if (it != end)
            return true;

        return false;
    }

    Node *expr() {
        Node *result = term();
        while (it != end && (it->TokenType == PLUS || it->TokenType == MINUS)) {
            if (it->TokenType == PLUS) {
                ++it;
                result = make_node(result, term(), '+');
            } else if (it->TokenType == MINUS) {
                ++it;
                result = make_node(result, term(), '-');
            }
        }
        return result;
    }

    Node *term() {
        Node *result = factor();
        while (it != end && (it->TokenType == MULTIPLY || it->TokenType == DIVIDE)) {
            if (it->TokenType == MULTIPLY) {
                ++it;
                result = make_node(result, factor(), '*');
            } else if (it->TokenType == DIVIDE) {
                ++it;
                result = make_node(result, factor(), '/');
            }
        }
        return result;
    }

    Node *factor() {
        if (it->TokenType == LPAREN) {
            ++it;
            Node* node = expr();
            if (it->TokenType != RPAREN)
                throw std::runtime_error("error: bad parenthesis\n");
            ++it;
            return node;
        } else if (it->TokenType == NUMBER) {
            Node *number_node = make_node(Convert::to_int(it->value));
            ++it;
            return number_node;
        } else if (it->TokenType == MINUS) {
            ++it;
            Node *number_node = make_node(make_node(-1), factor(), '*');
            return number_node;
        }
        throw std::runtime_error("error: wrong expression\n");
    }
};

#endif //ROMAN_NUMERALS_PARSER_H
