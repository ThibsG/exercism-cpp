#ifndef SUM_OF_MULTIPLES_H
#define SUM_OF_MULTIPLES_H

#include <vector>
#include <numeric>
#include <algorithm>

namespace sum_of_multiples
{

int to(int upTo, const std::vector<int>& dividers = {3, 5})
{
  auto start = dividers.front();
  if(upTo < start)
    return 0;

  std::vector<int> multiples;
  for(auto i = start ; i < upTo ; ++i)
  {
    auto match = std::find_if(dividers.begin(), dividers.end(), [&](int d){
      return i % d == 0;
    });

    if(match != dividers.end())
      multiples.push_back(i);
  }

  return std::accumulate(multiples.begin(), multiples.end(), 0);
}

int to(const std::vector<int>& init, int upTo)
{
  return to(upTo, init);
}

}

#endif