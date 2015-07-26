#ifndef ROBOT_NAME_H
#define ROBOT_NAME_H

#include <string>

namespace robot_name
{

/**
 * @class robot
 * Robot name generator
 */
class robot
{
  public:
    robot();

    const std::string& name() const;
    void reset();

  private:
    std::string m_name;

    char getRandomLetter() const;
    std::string getRandomNumber() const;
};

}

#endif