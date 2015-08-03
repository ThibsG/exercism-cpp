#ifndef GRAINS_H
#define GRAINS_H

#include <cstdint>
#include <bitset>

namespace grains
{

static const unsigned int MaxChessSquares = 64;

inline uint64_t square(unsigned int p)
{
  return std::bitset<MaxChessSquares>().set(p-1).to_ullong();
}

inline uint64_t total()
{
  return std::bitset<MaxChessSquares>().set().to_ullong();
}

}

#endif