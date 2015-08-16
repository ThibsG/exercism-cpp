#ifndef CLOCK_H
#define CLOCK_H

#include <string>
#include <cstdint>

namespace date_independent
{

class clock
{
  public:
    static clock at(int16_t hours, int16_t minutes = 0) noexcept;

    clock() = delete;

    clock& plus(int16_t minutes) noexcept;
    clock& minus(int16_t minutes) noexcept;

    inline bool operator==(const clock& c) const;
    inline bool operator!=(const clock& c) const;

    operator std::string() const;

  private:
    static constexpr auto s_minutesPerDay = 60 * 24; // 60 minutes * 24 hours

    clock(int16_t hours, int16_t minutes);

    int16_t m_minutes;
};

bool clock::operator==(const clock& c) const
{
  return m_minutes == c.m_minutes;
}

bool clock::operator!=(const clock& c) const
{
  return not (*this == c);
}

}

#endif