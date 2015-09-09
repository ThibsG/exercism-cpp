#ifndef TRINARY_H
#define TRINARY_H

#include <string>
#include <algorithm>
#include <cmath>

namespace trinary
{

namespace
{
constexpr auto numMin = '0';
constexpr auto numMax = '2';
constexpr auto asciiOffset = numMin;
}

unsigned int to_decimal(const std::string& input)
{
  if(std::any_of(input.cbegin(), input.cend(), [](char c){return c > numMax || c < numMin;}))
    return 0;

  auto decimal = 0;
  auto exp = input.size();

  for(const auto& c : input) {
    decimal += (c - asciiOffset) * std::pow(3, --exp);
  }

  return decimal;
}

}

#endif