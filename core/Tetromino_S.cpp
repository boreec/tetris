#include "Tetromino_S.hpp"

Tetris::core::Tetromino_S::Tetromino_S()
{

}

char Tetris::core::Tetromino_S::getChar() const{
    return S_CHAR;
}

std::array<std::array<char,4>,4> Tetris::core::Tetromino_S::getPiece(int orientation) const{
    if(!(orientation % 2))
        return {{
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, S_CHAR, S_CHAR},
            {EMPTY_CELL, S_CHAR, S_CHAR, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
        }};
    return {{
            {EMPTY_CELL, EMPTY_CELL, S_CHAR, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, S_CHAR, S_CHAR},
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, S_CHAR},
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
        }};

}
