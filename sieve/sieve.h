#ifndef SIEVE_H
#define SIEVE_H

#include <vector>
#include <list>
#include <numeric>

namespace sieve
{

std::vector<int> primes(int primesUpTo)
{
  std::vector<int> out;
  std::list<int> table(primesUpTo - 2);
  std::iota(table.begin(), table.end(), 2);

  while(not table.empty())
  {
    auto prime = table.front();
    out.push_back(prime);
    table.remove_if([&](int n){ return n % prime == 0;});
  }

  return out;
}

}

#endif