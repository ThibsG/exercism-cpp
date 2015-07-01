#ifndef WORD_COUNT_H
#define WORD_COUNT_H

#include <string>
#include <map>
#include <regex>
#include <boost/algorithm/string.hpp>

namespace word_count
{

std::map<std::string, int> words(const std::string& phrase)
{
  std::map<std::string, int> countingMap;

  if(phrase.empty())
    return countingMap;

  std::string filtered = boost::algorithm::to_lower_copy(phrase);
  // Replace by spaces multiple punctuations (at least 2) or comas
  filtered = std::regex_replace(filtered, std::regex("[[:punct:]]{2,}|[,]+"), " ");
  // Replace by spaces [spaces-punct] or [punct-spaces] or [punct-EOL]
  filtered = std::regex_replace(filtered, std::regex("[\\s]+[[:punct:]]|[[:punct:]][\\s]+|[[:punct:]]$"), " ");

  // Split string following \t, spaces or \n. Don't keep empty parts
  std::vector<std::string> strs;
  boost::split(strs, filtered, boost::is_any_of("\t\n "), boost::algorithm::token_compress_on);

  // Count strings through a map
  for(const auto& str : strs)
  {
    if(str.empty())
      continue;

    if(countingMap.find(str) == countingMap.end()) {
      countingMap[str] = 1;
    } else {
      ++countingMap[str];
    }
  }

  return countingMap;
}

}

#endif