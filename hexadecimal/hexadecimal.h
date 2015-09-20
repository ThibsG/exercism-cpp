#ifndef HEXADECIMAL_H
#define HEXADECIMAL_H

#include <string>
#include <cctype>

namespace hexadecimal
{

uint32_t convert(const std::string& number)
{
  auto pow = number.size();
  uint32_t hexa = 0;

  for(const auto& c : number)
  {
    auto ascii = 0;

    if(c >= '0' && c <= '9') {
      ascii = c - '0';
    } else {
      auto lowered = tolower(c);
      if(lowered >= 'a' && lowered <= 'f')
        ascii = lowered - 'a' + 10;
      else
        return 0;
    }

    hexa += ascii << (--pow * 4);
  }

  return hexa;
}

}

#endif