#ifndef GRAINS_H
#define GRAINS_H

#include <cstdint>
#include <unordered_map>

namespace grains
{

static const unsigned int MaxChessSquares = 64;

inline uint64_t square(unsigned int p)
{
  return static_cast<uint64_t>(1) << (p-1);
}

inline uint64_t total()
{
  auto total = square(0);
  for(auto i = 1 ; i < MaxChessSquares ; ++i)
    total += square(i);
  return total;
}

}

#endif