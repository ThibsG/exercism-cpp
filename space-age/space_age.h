#ifndef SPACE_AGE_H
#define SPACE_AGE_H

#include <cstdint>

namespace space_age
{

class space_age
{
  public:
    space_age(uint64_t seconds);

    inline uint64_t seconds() const;

    double on_earth() const;
    double on_mercury() const;
    double on_venus() const;
    double on_mars() const;
    double on_jupiter() const;
    double on_saturn() const;
    double on_uranus() const;
    double on_neptune() const;

  private:
    uint64_t m_seconds;
    double m_onEarth;
};

uint64_t space_age::seconds() const
{
  return m_seconds;
}

}

#endif