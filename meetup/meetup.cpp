#include "meetup.h"

namespace meetup
{

using namespace boost::gregorian;

scheduler::scheduler(date::month_type month, date::year_type year) :
  m_month(month),
  m_year(year)
{
}

date scheduler::teenth(weekdays day) const
{
  const date d(m_year, m_month, 13);
  const greg_weekday gw(day);
  return next_weekday(d, gw);
}

date scheduler::specificDay(nthDow::week_num weekNumber, weekdays day) const
{
  nthDow dm(weekNumber, day, m_month);
  return dm.get_date(m_year);
}

date scheduler::last(weekdays day) const
{
  last_day_of_the_week_in_month lastDay(day, m_month);
  return lastDay.get_date(m_year);
}

}