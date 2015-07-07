#ifndef NUCLEOTIDE_COUNT_H
#define NUCLEOTIDE_COUNT_H

#include <string>
#include <map>

namespace dna
{

/**
 * @class counter
 * The nucleotide counter class
 */
class counter
{
  public:
    counter(const std::string& sequence) :
      m_sequence(sequence)
    {
    }

    std::map<char, int> nucleotide_counts() const
    {
      std::map<char, int> counter{ {'A', 0}, {'T', 0}, {'C', 0}, {'G', 0} };
      for(auto c : m_sequence)
        ++counter[c];
      return counter;
    }

    int count(const char nucleotide) const
    {
      if(not isValid(nucleotide))
        throw std::invalid_argument("Input nucleotide is not valid");

      int counter = 0;
      for(auto c : m_sequence) {
        if(c == nucleotide)
          ++counter;
      }

      return counter;
    }

  private:
    std::string m_sequence;

    bool isValid(const char nucleotide) const
    {
      return nucleotide == 'A' || nucleotide == 'T' ||
             nucleotide == 'C' || nucleotide == 'G';
    }
};

}

#endif