#ifndef MEETUP_H
#define MEETUP_H

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/date_defs.hpp>

namespace meetup
{

using namespace boost::gregorian;
using boost::date_time::weekdays;
using nthDow = nth_day_of_the_week_in_month;

class scheduler
{
  public:
    scheduler(date::month_type month, date::year_type year);

    inline date monteenth() const;
    inline date tuesteenth() const;
    inline date wednesteenth() const;
    inline date thursteenth() const;
    inline date friteenth() const;
    inline date saturteenth() const;
    inline date sunteenth() const;

    inline date first_monday() const;
    inline date first_tuesday() const;
    inline date first_wednesday() const;
    inline date first_thursday() const;
    inline date first_friday() const;
    inline date first_saturday() const;
    inline date first_sunday() const;

    inline date last_monday() const;
    inline date last_tuesday() const;
    inline date last_wednesday() const;
    inline date last_thursday() const;
    inline date last_friday() const;
    inline date last_saturday() const;
    inline date last_sunday() const;

    inline date second_monday() const;
    inline date second_tuesday() const;
    inline date second_wednesday() const;
    inline date second_thursday() const;
    inline date second_friday() const;
    inline date second_saturday() const;
    inline date second_sunday() const;

    inline date third_monday() const;
    inline date third_tuesday() const;
    inline date third_wednesday() const;
    inline date third_thursday() const;
    inline date third_friday() const;
    inline date third_saturday() const;
    inline date third_sunday() const;

    inline date fourth_monday() const;
    inline date fourth_tuesday() const;
    inline date fourth_wednesday() const;
    inline date fourth_thursday() const;
    inline date fourth_friday() const;
    inline date fourth_saturday() const;
    inline date fourth_sunday() const;

  private:
    date::month_type m_month;
    date::year_type  m_year;

    date teenth(weekdays day) const;
    date last(weekdays day) const;
    date specificDay(nthDow::week_num weekNumber, weekdays day) const;
};

date scheduler::monteenth() const
{
  return teenth(Monday);
}

date scheduler::tuesteenth() const
{
  return teenth(Tuesday);
}

date scheduler::wednesteenth() const
{
  return teenth(Wednesday);
}

date scheduler::thursteenth() const
{
  return teenth(Thursday);
}

date scheduler::friteenth() const
{
  return teenth(Friday);
}

date scheduler::saturteenth() const
{
  return teenth(Saturday);
}

date scheduler::sunteenth() const
{
  return teenth(Sunday);
}

date scheduler::first_monday() const
{
  return specificDay(nthDow::first, Monday);
}

date scheduler::first_tuesday() const
{
  return specificDay(nthDow::first, Tuesday);
}

date scheduler::first_wednesday() const
{
  return specificDay(nthDow::first, Wednesday);
}

date scheduler::first_thursday() const
{
  return specificDay(nthDow::first, Thursday);
}

date scheduler::first_friday() const
{
  return specificDay(nthDow::first, Friday);
}

date scheduler::first_saturday() const
{
  return specificDay(nthDow::first, Saturday);
}

date scheduler::first_sunday() const
{
  return specificDay(nthDow::first, Sunday);
}

date scheduler::second_monday() const
{
  return specificDay(nthDow::second, Monday);
}

date scheduler::second_tuesday() const
{
  return specificDay(nthDow::second, Tuesday);
}

date scheduler::second_wednesday() const
{
  return specificDay(nthDow::second, Wednesday);
}

date scheduler::second_thursday() const
{
  return specificDay(nthDow::second, Thursday);
}

date scheduler::second_friday() const
{
  return specificDay(nthDow::second, Friday);
}

date scheduler::second_saturday() const
{
  return specificDay(nthDow::second, Saturday);
}

date scheduler::second_sunday() const
{
  return specificDay(nthDow::second, Sunday);
}

date scheduler::third_monday() const
{
  return specificDay(nthDow::third, Monday);
}

date scheduler::third_tuesday() const
{
  return specificDay(nthDow::third, Tuesday);
}

date scheduler::third_wednesday() const
{
  return specificDay(nthDow::third, Wednesday);
}

date scheduler::third_thursday() const
{
  return specificDay(nthDow::third, Thursday);
}

date scheduler::third_friday() const
{
  return specificDay(nthDow::third, Friday);
}

date scheduler::third_saturday() const
{
  return specificDay(nthDow::third, Saturday);
}

date scheduler::third_sunday() const
{
  return specificDay(nthDow::third, Sunday);
}

date scheduler::fourth_monday() const
{
  return specificDay(nthDow::fourth, Monday);
}

date scheduler::fourth_tuesday() const
{
  return specificDay(nthDow::fourth, Tuesday);
}

date scheduler::fourth_wednesday() const
{
  return specificDay(nthDow::fourth, Wednesday);
}

date scheduler::fourth_thursday() const
{
  return specificDay(nthDow::fourth, Thursday);
}

date scheduler::fourth_friday() const
{
  return specificDay(nthDow::fourth, Friday);
}

date scheduler::fourth_saturday() const
{
  return specificDay(nthDow::fourth, Saturday);
}

date scheduler::fourth_sunday() const
{
  return specificDay(nthDow::fourth, Sunday);
}

date scheduler::last_monday() const
{
  return last(Monday);
}

date scheduler::last_tuesday() const
{
  return last(Tuesday);
}

date scheduler::last_wednesday() const
{
  return last(Wednesday);
}

date scheduler::last_thursday() const
{
  return last(Thursday);
}

date scheduler::last_friday() const
{
  return last(Friday);
}

date scheduler::last_saturday() const
{
  return last(Saturday);
}

date scheduler::last_sunday() const
{
  return last(Sunday);
}

}

#endif