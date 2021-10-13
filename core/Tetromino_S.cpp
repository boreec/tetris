#include "Tetromino_S.hpp"

Tetromino_S::Tetromino_S()
{

}

char Tetromino_S::getChar() const{
    return S_CHAR;
}

std::array<std::array<char,4>,4> Tetromino_S::getPiece(int orientation) const{
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
