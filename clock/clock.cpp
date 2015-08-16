#include "clock.h"

#include <sstream>
#include <iomanip>

using namespace std;

namespace date_independent
{

clock clock::at(int16_t hours, int16_t minutes) noexcept
{
  return clock(hours, minutes);
}

clock::clock(int16_t hours, int16_t minutes) :
  m_minutes((hours * 60) + minutes)
{
}

clock& clock::plus(int16_t minutes) noexcept
{
  m_minutes += minutes;
  return *this;
}

clock& clock::minus(int16_t minutes) noexcept
{
  m_minutes -= minutes;

  if(m_minutes < 0) {
    m_minutes += s_minutesPerDay;
  }

  return *this;
}

clock::operator string() const
{
  int16_t hours = (m_minutes / 60) % 24;
  int16_t minutes = m_minutes % 60;

  stringstream ss;
  ss << setfill('0') << setw(2) << hours << ":"
     << setfill('0') << setw(2) << minutes;
  return ss.str();
}

}