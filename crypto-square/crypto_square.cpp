#include "crypto_square.h"

#include <algorithm>
#include <cmath>

using namespace std;

namespace crypto_square
{

cipher::cipher(const string& text) :
  m_text(text)
{
  copy_if(m_text.begin(), m_text.end(), back_inserter(m_normalized), ::isalnum);
  transform(m_normalized.begin(), m_normalized.end(), m_normalized.begin(), ::tolower);
  // Set size: if not a perfect square, use next number
  m_size = sqrt(m_normalized.size());
  if(pow(m_size, 2) != m_normalized.size())
    ++m_size;
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
      if(++cptChars == m_size) {
        cptChars = 0;
        ciphered += " ";
      }
    }
  }

  if(::isspace(ciphered.at(ciphered.size() - 1)))
    ciphered.pop_back();
  return ciphered;
}

}