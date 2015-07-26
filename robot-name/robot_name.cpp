#include "robot_name.h"

#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

namespace robot_name
{

namespace {
  bool randInit = false;
}

robot::robot()
{
  if(not randInit) {
    srand(time(0));
    randInit = true;
  }

  reset();
}

const string& robot::name() const
{
  return m_name;
}

void robot::reset()
{
  auto lastName = m_name;

  do {
    m_name  = getRandomLetter();
    m_name += getRandomLetter();
    m_name += getRandomNumber();
  } while(lastName == m_name);
}

char robot::getRandomLetter() const
{
  return 'A' + (random() % 26);
}

string robot::getRandomNumber() const
{
  stringstream ss;
  ss << setfill('0') << setw(3) << (random() % 999);
  return ss.str();
}

}