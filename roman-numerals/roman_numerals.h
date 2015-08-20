#ifndef ROMAN_NUMERALS_H
#define ROMAN_NUMERALS_H

#include <sstream>

namespace roman
{

std::string getRomanLetters(int digit,
                            char numeral,
                            const std::string& fourth,
                            const std::string& ninth,
                            const std::string& gtFive) noexcept
{
  if(digit == 0)    return "";
  if(digit == 4)    return fourth;
  if(digit == 9)    return ninth;

  std::string pre;
  if(digit >= 5) {
    pre = gtFive;
    digit -= 5;
  }

  return pre + std::string(digit, numeral);
}

std::string convert(int num) noexcept
{
  std::stringstream ss;

  ss << std::string(num / 1000, 'M');                             // X...
  ss << getRomanLetters(num % 1000 / 100, 'C', "CD", "CM", "D");  // .X..
  ss << getRomanLetters(num % 100  / 10,  'X', "XL", "XC", "L");  // ..X.
  ss << getRomanLetters(num % 10,         'I', "IV", "IX", "V");  // ...X

  return ss.str();
};

}

#endif