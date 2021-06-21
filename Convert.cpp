//
// Created by Maxim Bordyugov on 16/06/2021.
//

#include <stdexcept>

#include "Convert.h"

const vector<string> Convert::thousands{"", "M", "MM", "MMM"};
const vector<string> Convert::hundreds{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
const vector<string> Convert::tens{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const vector<string> Convert::ones{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

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

long long int Convert::to_int(string &str) {
  if (str.empty()) {
    throw std::runtime_error("error: wrong expression\n");
  }
  long long int res = 0;
  size_t i = (str[0] == '-') ? 1 : 0;
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

string Convert::to_roman(long long int y) {
  if (y == 0) return "Z";
  if (std::abs(y) >= 4000)
    throw std::overflow_error("error: integer " + std::to_string(y)
                                  + " cannot be represented in roman numerals."
                                  + " Allowed integers are [-3999, 3999]\n");
  long long int x = (y < 0) ? -y : y;
  string ans = thousands[x / 1000] + hundreds[(x % 1000) / 100] + tens[(x % 100) / 10] + ones[x % 10];
  if (y < 0) {
    ans = "-" + ans;
  }
  return ans;
}