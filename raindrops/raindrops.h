#ifndef RAINDROPS_H
#define RAINDROPS_H

#include <sstream>
#include <map>

namespace raindrops
{

std::string convert(uint32_t num) noexcept
{
  auto hasPrimeFactor = false;
  std::stringstream ss;
  std::map<uint32_t, std::string> factors{{3,"Pling"}, {5,"Plang"}, {7,"Plong"}};

  for(const auto& f : factors) {
    if(num % f.first == 0) {
      ss << f.second;
      hasPrimeFactor = true;
    }
  }

  return hasPrimeFactor ? ss.str() : std::to_string(num);
}

}

#endif