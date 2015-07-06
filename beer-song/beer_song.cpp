#include "beer_song.h"

#include <sstream>

using namespace std;

namespace beer
{

string verse(int verseNumber)
{
  if(verseNumber == 2)
  {
    return "2 bottles of beer on the wall, 2 bottles of beer.\n"
           "Take one down and pass it around, 1 bottle of beer on the wall.\n";
  }
  else if(verseNumber == 1)
  {
    return "1 bottle of beer on the wall, 1 bottle of beer.\n"
           "Take it down and pass it around, no more bottles of beer on the wall.\n";
  }
  else if(verseNumber <= 0)
  {
    return "No more bottles of beer on the wall, no more bottles of beer.\n"
           "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
  }

  stringstream ss;
  ss << verseNumber << " bottles" << " of beer on the wall, "
     << verseNumber << " bottles" << " of beer.\nTake "
     << "one down and pass it around, " << (verseNumber - 1)
     << " bottles" << " of beer on the wall.\n";

  return ss.str();
}

string sing(int start, int end)
{
  stringstream ss;
  for(auto i = start ; i >= end ; --i)
    ss << verse(i) << (i != end ? "\n" : "");
  return ss.str();
}

}