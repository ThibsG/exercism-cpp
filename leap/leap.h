#ifndef LEAP_H
#define LEAP_H

namespace leap
{

static bool is_leap_year(unsigned int year)
{
  return !(year % 4) and ((year % 100) or !(year % 400));
}

}

#endif