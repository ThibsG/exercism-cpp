#ifndef GIGASECOND_H
#define GIGASECOND_H

#include <cmath>
#include <boost/date_time/gregorian/gregorian.hpp>

namespace gigasecond
{

namespace
{

const auto gigasecond    = std::pow(10.0, 9.0);
const auto secsInDay     = 86400; // 24 * 60 * 60
const auto daysInGigaSec = gigasecond / secsInDay;

}

boost::gregorian::date advance(const boost::gregorian::date& date)
{
  return date + boost::gregorian::date_duration(daysInGigaSec);
}

}

#endif