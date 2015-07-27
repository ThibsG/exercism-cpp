#include "space_age.h"

namespace space_age
{

space_age::space_age(uint64_t seconds) :
  m_seconds(seconds),
  m_onEarth(static_cast<double>(m_seconds) / 31557600)
{
}

double space_age::on_earth() const
{
  return m_onEarth;
}

double space_age::on_mercury() const
{
  return m_onEarth / 0.2408467;
}

double space_age::on_venus() const
{
  return m_onEarth / 0.61519726;
}

double space_age::on_mars() const
{
  return m_onEarth / 1.8808158;
}

double space_age::on_jupiter() const
{
  return m_onEarth / 11.862615;
}

double space_age::on_saturn() const
{
  return m_onEarth / 29.447498;
}

double space_age::on_uranus() const
{
  return m_onEarth / 84.016846;
}

double space_age::on_neptune() const
{
  return m_onEarth / 164.79132;
}

}