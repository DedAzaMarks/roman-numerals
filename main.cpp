#include <cassert>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::to_string;

int symbol(char c) {
    if (c == 'I') return 1;
    if (c == 'V') return 5;
    if (c == 'X') return 10;
    if (c == 'L') return 50;
    if (c == 'C') return 100;
    if (c == 'D') return 500;
    if (c == 'M') return 1000;

    return -1;
}

int64_t roman_to_int(string& str) {
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

string int_to_roman(int64_t x) {
    if (x == 0) return "Z";
    string hundreds[] = {
            "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string tens[] = {
            "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string ones[] = {
            "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string ans(x / 1000, 'M');
    ans += hundreds[(x % 1000) / 100] + tens[(x % 100) / 10] + ones[x % 10];
    return ans;
}

int main() {
    string str = "";
    for (int i = 0; i < 1000000; ++i) {
        string r = int_to_roman(i);
        int n = roman_to_int(r);
        cout << "i = " << i << " r = " << r << " n = " << n << "\n";
        assert(n == i);
    }
    return 0;
}