#ifndef BINARY_H
#define BINARY_H

#include <string>

namespace binary
{

namespace
{
constexpr auto asciiOffset = 48;
}

int convert(const std::string& binary)
{
  auto pow = binary.size();
  auto number = 0;

  for(const auto& c : binary)
  {
    if(c != '1' && c != '0') {
      return 0;
    } else if(c == '1') {
      number += (c - asciiOffset) << (pow - 1);
    }

    --pow;
  }

  return number;
}

}

#endif