#ifndef CRYPTO_SQUARE_H
#define CRYPTO_SQUARE_H

#include <cstdint>
#include <string>
#include <vector>

namespace crypto_square
{

class cipher
{
  public:
    cipher(const std::string& text);

    uint32_t size() const;
    std::string normalize_plain_text() const;
    std::vector<std::string> plain_text_segments() const;
    std::string normalized_cipher_text() const;
    std::string cipher_text() const;

  private:
    std::string m_text;
    std::string m_normalized;
    uint32_t m_size;
};

}

#endif