//
// Created by Maxim Bordyugov on 16/06/2021.
//

#ifndef ROMAN_NUMERALS_CONVERT_H
#define ROMAN_NUMERALS_CONVERT_H

#include <string>

using std::string;

class Convert {
private:
    static const string hundreds[10];
    static const string tens[10];
    static const string ones[10];
public:
    static int symbol(char c);

    static int64_t to_int(string& str);

    static string to_roman(int64_t x);
};

#endif //ROMAN_NUMERALS_CONVERT_H
