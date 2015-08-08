#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <exception>
#include <stdexcept>

namespace triangle
{

enum Type
{
  illegal,
  equilateral,
  isosceles,
  scalene,
};

Type kind(float s1, float s2, float s3)
{
  if(s1 == 0 or s2 == 0 or s3 == 0)
    throw std::domain_error("A triangle side cannot be zero length");

  auto inequality = (s1 + s2) > s3 and
                    (s2 + s3) > s1 and
                    (s1 + s3) > s2;

  if(not inequality or s1 < 0 or s2 < 0 or s3 < 0)
    return illegal;

  if(s1 == s2 and s2 == s3)
    return equilateral;

  if(s1 == s2 or s2 == s3 or s1 == s3)
    return isosceles;

  if(s1 != s2 and s2 != s3 and s1 != s3)
    return scalene;

  throw std::logic_error("Impossible to find triangle type");
}

}

#endif