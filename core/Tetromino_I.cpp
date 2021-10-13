#include "Tetromino_I.hpp"

Tetromino_I::Tetromino_I()
{

}

char Tetromino_I::getChar() const {
    return I_CHAR;
}

std::array<std::array<char,4>,4> Tetromino_I::getPiece(int orientation) const{
    if(!orientation || m_orientation == 2)
        return {{
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
            {I_CHAR, I_CHAR, I_CHAR, I_CHAR},
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
        }};
    return {{
            {EMPTY_CELL, EMPTY_CELL, I_CHAR, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, I_CHAR, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, I_CHAR, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, I_CHAR, EMPTY_CELL}
        }};

}
