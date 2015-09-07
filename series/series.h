#ifndef SERIES_H
#define SERIES_H

#include <vector>
#include <string>
#include <stdexcept>

namespace series
{

namespace
{
constexpr auto asciiOffset = '0';
}

std::vector<int> digits(const std::string& digitStr) noexcept
{
  std::vector<int> digits;
  for(auto c : digitStr)
    digits.push_back(c - asciiOffset);
  return digits;
}

std::vector<std::vector<int>> slice(const std::string& digitStr, int nbItems)
{
  if(nbItems > digitStr.size())
    throw std::domain_error("Not enough digits to slice");

  std::vector<std::vector<int>> sliced;
  auto digitalize = digits(digitStr);

  for(auto i = 0 ; i <= digitalize.size() - nbItems ; ++i)
  {
    auto start = digitalize.cbegin() + i;
    sliced.push_back(std::vector<int>(start, start + nbItems));
  }

  return sliced;
}

}

#endif