//
// Created by Maxim Bordyugov on 16/06/2021.
//
#ifndef ROMAN_NUMERALS_CONVERT_H
#define ROMAN_NUMERALS_CONVERT_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Convert {
 private:
  static const vector<string> thousands;
  static const vector<string> hundreds;
  static const vector<string> tens;
  static const vector<string> ones;

 public:
  static int symbol(char c);
  static int64_t to_int(string &str);
  static string to_roman(int64_t x);
};

#endif //ROMAN_NUMERALS_CONVERT_H
