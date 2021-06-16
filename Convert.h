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

    static int symbol(char c) {
        if (c == 'I') return 1;
        if (c == 'V') return 5;
        if (c == 'X') return 10;
        if (c == 'L') return 50;
        if (c == 'C') return 100;
        if (c == 'D') return 500;
        if (c == 'M') return 1000;
        return -1;
    }
public:
    static int64_t to_int(string& str) {
        int64_t res = 0;
        if (str == "Z") return 0;
        for (size_t i = 0; i < str.length(); ++i) {
            int cur = symbol(str[i]);
            if (i + 1 < str.length()) {
                // Getting value of symbol s[i+1]
                int next = symbol(str[i + 1]);

                // Comparing both values
                if (cur >= next) {
                    // Value of current symbol
                    // is greater or equal to
                    // the next symbol
                    res += cur;
                } else {
                    // Value of current symbol is
                    // less than the next symbol
                    res += next - cur;
                    i++;
                }
            } else {
                res += cur;
            }
        }
        return res;
    }

    static string to_roman(int64_t x) {
        if (x == 0) return "Z";
        string ans(x / 1000, 'M');
        ans += hundreds[(x % 1000) / 100] + tens[(x % 100) / 10] + ones[x % 10];
        return ans;
    }
};


#endif //ROMAN_NUMERALS_CONVERT_H
