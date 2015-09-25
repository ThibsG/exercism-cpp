#include "say.h"

#include <map>
#include <stdexcept>

namespace say
{

namespace
{
constexpr uint64_t maxNum   = 999999999999;
constexpr uint64_t hundred  = 100;
constexpr uint64_t thousand = 1000;
constexpr uint64_t million  = 1000000;
constexpr uint64_t billion  = 1000000000;

const std::map<uint64_t, std::string> table =
  {{0,"zero"},{1,"one"},{2,"two"},{3,"three"},{4,"four"},{5,"five"},{6,"six"},{7,"seven"},{8,"eight"},{9,"nine"}
  ,{10,"ten"},{11,"eleven"},{12,"twelve"},{13,"thirteen"},{14,"fourteen"},{15,"fifteen"},{16,"sixteen"}
  ,{17,"seventeen"},{18,"eighteen"},{19,"nineteen"},{20,"twenty"},{30,"thirty"},{40,"forty"},{50,"fifty"}
  ,{60,"sixty"},{70,"seventy"},{80,"eighty"},{90,"ninety"},{hundred,"hundred"},{thousand,"thousand"}
  ,{million,"million"},{billion,"billion"}};
}

std::string spellOut(uint64_t number) noexcept;
void getChunk(std::string& spell, uint64_t& num, uint64_t step) noexcept;

std::string in_english(uint64_t input)
{
  if(static_cast<int64_t>(input) < 0 || input > maxNum)
    throw std::domain_error("Bad range !");

  if(input < hundred && table.find(input) != table.cend())
    return table.at(input);

  std::string converted;
  getChunk(converted, input, billion);
  getChunk(converted, input, million);
  getChunk(converted, input, thousand);
  if(input % thousand > 0)
    converted += spellOut(input % thousand);

  if(::isspace(converted.back()))
    converted.pop_back();
  return converted;
}

void getChunk(std::string& spell, uint64_t& num, uint64_t step) noexcept
{
  auto conv = spellOut(num / step);
  if(not conv.empty())
    spell += conv + " " + table.at(step) + " ";
  num %= step;
}

std::string spellOut(uint64_t number) noexcept
{
  if(number == 0)
    return "";

  std::string conv;
  uint64_t lastNumber = 0;

  for(auto it = table.crbegin() ; it != table.crend() ; ++it)
  {
    if(table.find(number) != table.end())
    {
      if(number < 10 && lastNumber > 0) {
        conv.pop_back();
        conv += "-";
      } else if(number >= hundred) {
        auto cit = table.lower_bound(number);
        conv += table.at(number / cit->first) + " ";
      }
      conv += table.at(number);
      break;
    }

    if(number < it->first)
      continue;

    if(it->first >= hundred)
      conv += table.at(number / it->first) + " ";

    conv += table.at(it->first) + " ";
    lastNumber = it->first;
    number %= it->first;
  }

  return conv;
}

}