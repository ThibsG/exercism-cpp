#ifndef PRIME_FACTORS_H
#define PRIME_FACTORS_H

#include <vector>

namespace prime_factors
{

std::vector<int> of(int natural)
{
  std::vector<int> primes;

  if(natural <= 1)
    return primes;

  auto divider = 2;

  while(natural != 1)
  {
    if(natural % divider == 0) {
      natural /= divider;
      primes.push_back(divider);
      continue;
    }

    ++divider;
  }

  return primes;
}

}

#endif