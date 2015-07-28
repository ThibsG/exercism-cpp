#ifndef ETL_H
#define ETL_H

#include <map>
#include <vector>

namespace etl
{

std::map<char, int> transform(const std::map<int, std::vector<char>>& old)
{
  std::map<char, int> newFormat;

  for(const auto& p : old) {
    for(auto c : p.second) {
      newFormat[tolower(c)] = p.first;
    }
  }

  return newFormat;
}

}

#endif