#include "anagram.h"

#include <boost/algorithm/string.hpp>

using namespace std;

namespace anagram
{

Anagram::Anagram(const string& ref) :
  m_ref(ref)
{
}

/// Look in the input @a list to get compatible anagrams with m_ref
vector<string> Anagram::matches(const initializer_list<string>& list) const
{
  vector<string> matched;

  for(auto elt : list)
  {
    // Discards element if sizes are different
    if(elt.length() != m_ref.length())
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
  auto lowerRef = boost::algorithm::to_lower_copy(m_ref);
  auto lowerCmp = boost::algorithm::to_lower_copy(cmp);

  // If same string (case insensitive), discards it
  if(lowerRef == lowerCmp)
    return false;

  auto mapRef = getStatLettersAnalysis(lowerRef);
  auto mapCmp = getStatLettersAnalysis(lowerCmp);
  return mapRef == mapCmp;
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