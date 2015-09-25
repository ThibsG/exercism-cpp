#ifndef SAY_H
#define SAY_H

#include <cstdint>
#include <string>
#include <vector>

namespace say
{

std::string in_english(uint64_t input);
std::string spellOut(uint64_t number) noexcept;
void getChunk(std::string& spell, uint64_t& num, uint64_t step) noexcept;

}

#endif