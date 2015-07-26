#include "grade_school.h"

#include <algorithm>

using namespace std;

namespace grade_school
{

void school::add(const string& name, int grade)
{
  auto& students = m_roster[grade];
  students.push_back(name);
  sort(students.begin(), students.end());
}

Students school::grade(int grade) const
{
  auto it = m_roster.find(grade);

  if(it == m_roster.cend())
    return Students();

  return it->second;
}

const Roster& school::roster() const
{
  return m_roster;
}

}