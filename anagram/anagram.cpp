#include "anagram.h"

#include <boost/algorithm/string.hpp>

using namespace std;

namespace anagram
{

Anagram::Anagram(const string& ref) :
  m_lowerRef(boost::algorithm::to_lower_copy(ref)),
  m_mapRef(getStatLettersAnalysis(m_lowerRef))
{
}

/// Look in input @a list to find compatible anagrams with m_lowerRef
vector<string> Anagram::matches(const initializer_list<string>& list) const
{
  vector<string> matched;

  for(auto elt : list)
  {
    // Discards element if sizes are different
    if(elt.length() != m_lowerRef.length())
      continue;

    // Store copy of element if it matches
    if(containsSameLettersAs(elt))
      matched.push_back(elt);
  }

  return matched;
}

/// Compare letter-occurence maps between @a cmp and m_ref
bool Anagram::containsSameLettersAs(const string& cmp) const
{
  auto lowerCmp = boost::algorithm::to_lower_copy(cmp);
  // If same string (case insensitive due to lowercase), discards it
  return m_lowerRef != lowerCmp and m_mapRef == getStatLettersAnalysis(lowerCmp);
}

/// Returns a map containing the letters and the number of occurences for each of them
map<char, int> Anagram::getStatLettersAnalysis(const string& input) const
{
  map<char, int> mapLetters;

  for(auto c : input)
  {
    if(mapLetters.find(c) == mapLetters.end())
      mapLetters[c] = 1;
    else
      ++mapLetters[c];
  }

  return mapLetters;
}

}