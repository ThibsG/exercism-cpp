#include "crypto_square.h"

#include <algorithm>
#include <cmath>

using namespace std;

namespace crypto_square
{

cipher::cipher(const string& text)
{
  copy_if(text.begin(), text.end(), back_inserter(m_normalized), ::isalnum);
  transform(m_normalized.begin(), m_normalized.end(), m_normalized.begin(), ::tolower);
  m_size = ceil(sqrt(m_normalized.size()));
}

uint32_t cipher::size() const
{
  return m_size;
}

string cipher::normalize_plain_text() const
{
  return m_normalized;
}

vector<string> cipher::plain_text_segments() const
{
  vector<string> segments;
  for(auto pos = 0 ; pos < m_normalized.length() ; pos += m_size)
    segments.push_back(m_normalized.substr(pos, m_size));
  return segments;
}

string cipher::cipher_text() const
{
  auto ciphered = normalized_cipher_text();
  ciphered.erase(remove_if(ciphered.begin(), ciphered.end(), ::isspace), ciphered.end());
  return ciphered;
}

string cipher::normalized_cipher_text() const
{
  const auto segments = plain_text_segments();
  string ciphered;

  for(auto i = 0, cptChars = 0 ; i < m_size ; ++i)
  {
    for(const auto& seg : segments)
    {
      if(i >= seg.size())
        continue;

      ciphered += seg[i];
      if(++cptChars % m_size == 0)
        ciphered += " ";
    }
  }

  if(isspace(ciphered.back()))
    ciphered.pop_back();
  return ciphered;
}

}