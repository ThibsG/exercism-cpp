#ifndef GRADE_SCHOOL_H
#define GRADE_SCHOOL_H

#include <map>
#include <vector>
#include <string>

namespace grade_school
{

typedef std::vector<std::string> Students;
typedef std::map<int, Students>  Roster;

/**
 * @class school
 * School roster handler
 */
class school
{
  public:
    void add(const std::string& name, int grade);
    Students grade(int grade) const;
    const Roster& roster() const;

  private:
    Roster m_roster;
};

}

#endif