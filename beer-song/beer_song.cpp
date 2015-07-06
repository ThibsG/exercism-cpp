#include "beer_song.h"

#include <sstream>

using namespace std;

namespace beer
{

static string getVerse(int verseNumber);

string verse(int verseNumber)
{
  return getVerse(verseNumber);
}

string sing(int start, int end)
{
  stringstream ss;
  for(auto i = start ; i >= end ; --i)
    ss << getVerse(i) << (i != end ? "\n" : "");
  return ss.str();
}

static string getVerse(int verseNumber)
{
  if(verseNumber <= 0)
  {
    return "No more bottles of beer on the wall, no more bottles of beer.\n"
           "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
  }

  const bool moreThanOneBeer = verseNumber > 1;

  stringstream ss;
  ss << verseNumber << " bottle" << (moreThanOneBeer?"s":"") << " of beer on the wall, "
     << verseNumber << " bottle" << (moreThanOneBeer?"s":"") << " of beer.\nTake ";

  if(verseNumber > 1)
  {
    const bool moreThanTwoBeer = (verseNumber - 1) > 1;
    ss << "one down and pass it around, " << (verseNumber - 1)
       << " bottle" << (moreThanTwoBeer?"s":"") << " of beer on the wall.\n";
  }
  else if(verseNumber == 1)
  {
    ss << "it down and pass it around, no more bottles of beer on the wall.\n";
  }

  return ss.str();
}

}