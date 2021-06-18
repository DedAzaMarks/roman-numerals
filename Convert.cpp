//
// Created by Maxim Bordyugov on 16/06/2021.
//

#include "Convert.h"

const string Convert::hundreds[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
const string Convert::tens[10] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
const string Convert::ones[10] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

int Convert::symbol(char c) {
    if (c == 'Z') return 0;
    if (c == 'I') return 1;
    if (c == 'V') return 5;
    if (c == 'X') return 10;
    if (c == 'L') return 50;
    if (c == 'C') return 100;
    if (c == 'D') return 500;
    if (c == 'M') return 1000;
    return -1;
}

int64_t Convert::to_int(string& str) {
    int64_t res = 0;
    size_t i = 0;
    if (str[0] == '-') {
        i = 1;
    }
    if (str == "Z") return 0;
    for (; i < str.length(); ++i) {
        int cur = symbol(str[i]);
        if (i + 1 < str.length()) {
            int next = symbol(str[i + 1]);
            if (cur >= next) {
                res += cur;
            } else {
                res += next - cur;
                i++;
            }
        } else {
            res += cur;
        }
    }
    if (str[0] == '-')
        res = -res;
    return res;
}

string Convert::to_roman(int64_t y) {
    if (y == 0) return "Z";
    int64_t x = 0;
    if (y < 0) {
        x = -y;
    } else {
        x = y;
    }
    string ans(x / 1000, 'M');
    ans += hundreds[(x % 1000) / 100] + tens[(x % 100) / 10] + ones[x % 10];
    if (y < 0) {
        ans = "-" + ans;
    }
    return ans;
}