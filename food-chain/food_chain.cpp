#include "food_chain.h"

#include <vector>
#include <fstream>

using namespace std;

namespace food_chain
{

/**
 * @class Song
 * Stores a song and provides interface
 */
class Song
{
  public:
    explicit Song(const string& filename) :
      m_filename(filename)
    {
      load();
    }

    /// Returns a specific verse
    string verse(int verseNumber) const
    {
      return m_verses.at(verseNumber);
    }

    /// Returns all verses of the song
    string verses() const
    {
      return verses(0, m_verses.size());
    }

    /// Returns multiple verses
    string verses(int start, int end) const
    {
      string accumulatedVerse;
      vector<string>::const_iterator it;
      auto itStart = m_verses.cbegin() + start;
      auto itEnd   = m_verses.cbegin() + end;

      for(it = itStart ; it != itEnd ; ++it)
      {
        accumulatedVerse += (*it) + "\n";
      }

      return accumulatedVerse;
    }

  private:
    string m_filename;
    vector<string> m_verses;

    /// Loads the file using ctor parameter
    void load()
    {
      ifstream infile(m_filename);
      string line, verse;
      while(getline(infile, line))
      {
        if(line.empty()) {
          m_verses.push_back(verse);
          verse.clear();
          continue;
        }
        verse += line + "\n";
      }
      // add last verse
      m_verses.push_back(verse);
    }
};

/// Singleton Song static instance
static Song s_instance = Song("../song.txt");

string verse(int startVerse)
{
  return s_instance.verse(startVerse - 1);
}

string verses(int startVerse, int endVerse)
{
  int start = startVerse - 1;

  if(endVerse <= 0)
    endVerse = start + 1;

  return s_instance.verses(start, endVerse);
}

string sing()
{
  return s_instance.verses();
}

}