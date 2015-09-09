#ifndef TRINARY_H
#define TRINARY_H

#include <string>
#include <algorithm>

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

  return std::accumulate(input.cbegin(), input.cend(), 0, [](std::size_t l, char c) {
    return (c - asciiOffset) + (l * 3);
  });
}

}

#endif