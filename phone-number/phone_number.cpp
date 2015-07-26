#include "phone_number.h"

#include <regex>

using namespace std;

namespace Telephony
{

phone_number::phone_number(const std::string& number) :
  m_areaCode("000"),
  m_highNumber("000"),
  m_lowNumber("0000")
{
  smatch match;
  if(regex_search(number, match, regex("^1?[^\\d]*(\\d{3})[^\\d]*(\\d{3})[^\\d]*(\\d{4})$"))) {
    m_areaCode   = match[1];
    m_highNumber = match[2];
    m_lowNumber  = match[3];
  }
}

string phone_number::number() const
{
  return m_areaCode + m_highNumber + m_lowNumber;
}

string phone_number::area_code() const
{
  return m_areaCode;
}

phone_number::operator string() const
{
  return "(" + m_areaCode + ") " + m_highNumber + "-" + m_lowNumber;
}

}