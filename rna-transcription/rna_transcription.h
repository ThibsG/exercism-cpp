#ifndef RNA_TRANSCRIPTION_H
#define RNA_TRANSCRIPTION_H

#include <string>
#include <system_error>

namespace transcription
{

static const char cytosine = 'C';
static const char guanine  = 'G';
static const char thymine  = 'T';
static const char adenine  = 'A';
static const char uracil   = 'U';

char to_rna(const char nucleotide)
{
  if(nucleotide == cytosine)   return guanine;
  if(nucleotide == guanine)    return cytosine;
  if(nucleotide == thymine)    return adenine;
  if(nucleotide == adenine)    return uracil;
  throw std::invalid_argument("Invalid input nucleotide");
}

std::string to_rna(const std::string& sequence)
{
  std::string rna;
  for(auto c : sequence)
    rna += to_rna(c);
  return rna;
}

}

#endif