#ifndef HAMMING_H
#define HAMMING_H

#include <string>
#include <system_error>

namespace hamming
{

int compute(const std::string& s1, const std::string& s2)
{
  if(s1.length() != s2.length())
    throw std::domain_error("lengths are different");

  if(s1.empty() || s1 == s2)
    return 0;

  auto diff = 0;
  for(auto i = 0 ; i < s1.length() ; ++i)
  {
    if(s1[i] != s2[i])
      ++diff;
  }
  return diff;
}

}

#endif