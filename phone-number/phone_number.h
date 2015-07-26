#ifndef PHONE_NUMBER_H
#define PHONE_NUMBER_H

#include <string>

inline namespace Telephony
{

/**
 * @class phone_number
 * Reads into string formated phone numbers
 */
class phone_number
{
  public:
    phone_number(const std::string& number);

    std::string number() const;
    std::string area_code() const;

    operator std::string() const;

  private:
    std::string m_areaCode;
    std::string m_lowNumber;
    std::string m_highNumber;
};

}

#endif