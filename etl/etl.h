#ifndef ETL_H
#define ETL_H

#include <map>
#include <vector>

namespace etl
{

std::map<char, int> transform(const std::map<int, std::vector<char>>& old)
{
  std::map<char, int> newFormat;

  for(auto it = old.cbegin() ; it != old.cend() ; ++it)
  {
    for(auto c : it->second)
      newFormat[tolower(c)] = it->first;
  }

  return newFormat;
}

}

#endif