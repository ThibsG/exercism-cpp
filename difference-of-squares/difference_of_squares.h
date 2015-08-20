#ifndef DIFFERENCE_OF_SQUARES_H
#define DIFFERENCE_OF_SQUARES_H

#include <cstdint>
#include <cmath>

namespace squares
{

int square_of_sums(int num) noexcept
{
  auto sum = 0;
  for(auto i = 1 ; i <= num ; ++i) {
    sum += i;
  }
  return std::pow(sum, 2);
};

int sum_of_squares(int num) noexcept
{
  auto sum = 0;
  for(auto i = 1 ; i <= num ; ++i) {
    sum += std::pow(i, 2);
  }
  return sum;
};

int difference(int num) noexcept
{
  return square_of_sums(num) - sum_of_squares(num);
};

}

#endif