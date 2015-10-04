#include "queen_attack.h"

#include <sstream>
#include <stdexcept>

using namespace std;

namespace queen_attack
{

chess_board::chess_board() :
  m_white(make_pair(0, 3)),
  m_black(make_pair(7, 3))
{
}

chess_board::chess_board(const piece& white, const piece& black) :
  m_white(white),
  m_black(black)
{
  if(m_white == m_black)
    throw domain_error("Queen positions must be distinct");
}

chess_board::operator string() const
{
  stringstream ss;
  const auto whitePos = (m_white.first * nbRowsCols) + m_white.second;
  const auto blackPos = (m_black.first * nbRowsCols) + m_black.second;

  for(auto i = 0 ; i < nbSquares ; ++i)
  {
    if(i == whitePos)      ss << "W";
    else if(i == blackPos) ss << "B";
    else                   ss << "_";
    ss << (((i+1) % nbRowsCols == 0) ? "\n" : " ");
  }

  return ss.str();
}

bool chess_board::can_attack() const
{
  // Same row or column, or pieces in diagonal
  return m_white.first  == m_black.first  ||
         m_white.second == m_black.second ||
         ::abs(m_white.first - m_black.first) == ::abs(m_white.second - m_black.second);
}

}