#ifndef NTH_PRIME_H
#define NTH_PRIME_H

#include <stdexcept>

namespace prime
{

namespace
{

inline bool isPrime(int number)
{
  for(auto i = 2 ; i < number ; ++i)
  {
    if((number % i) == 0)
      return false;
  }

  return true;
}

}

inline int nth(int prime)
{
  auto nbPrimes = 0;

  for(auto i = 2 ; nbPrimes < prime ; ++i)
  {
    if(isPrime(i) && ++nbPrimes == prime)
        return i;
  }

  throw std::domain_error("prime has not been found");
}

}

#endif