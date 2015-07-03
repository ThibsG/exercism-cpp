#ifndef ANAGRAM_H
#define ANAGRAM_H

#include <string>
#include <vector>
#include <map>

namespace anagram
{

/**
 * @class Anagram
 * Detects anagram(s)
 *
 * Build the object with the string (the reference) you want to test.
 * Give a list of string to compare with your ref, using 'matches'.
 * It returns you a subset of matches param, containing strings that
 */
class Anagram
{
  public:
    explicit Anagram(const std::string& ref);

    std::vector<std::string> matches(const std::initializer_list<std::string>& list) const;

  private:
    std::string m_lowerRef;
    std::map<char, int> m_mapRef;

    bool containsSameLettersAs(const std::string& cmp) const;
    std::map<char, int> getStatLettersAnalysis(const std::string& input) const;
};

/// Builds and returns an Anagram object
static Anagram anagram(const std::string& s)
{
  return Anagram(s);
}

}

#endif