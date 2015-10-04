#ifndef QUEEN_ATTACK_H
#define QUEEN_ATTACK_H

#include <string>
#include <utility>

namespace queen_attack
{

/// A piece of chessboard is defined by its position: row, column
using piece = std::pair<int, int>;

class chess_board
{
  public:
    chess_board();
    chess_board(const piece& white, const piece& black);

    bool can_attack() const;
    inline const piece& white() const;
    inline const piece& black() const;

    operator std::string() const;

  private:
    static constexpr auto nbRowsCols = 8;
    static constexpr auto nbSquares = nbRowsCols * nbRowsCols;

    const piece m_white;
    const piece m_black;
};

const piece& chess_board::white() const
{
  return m_white;
}

const piece& chess_board::black() const
{
  return m_black;
}

}

#endif