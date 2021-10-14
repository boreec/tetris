#include "Tetromino_L.hpp"

Tetris::core::Tetromino_L::Tetromino_L()
{

}

char Tetris::core::Tetromino_L::getChar() const{
    return L_CHAR;
}

std::array<std::array<char,4>,4> Tetris::core::Tetromino_L::getPiece(int orientation) const{
    if(!orientation)
        return {{
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
            {EMPTY_CELL, L_CHAR, L_CHAR, L_CHAR},
            {EMPTY_CELL, L_CHAR, EMPTY_CELL, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
        }};
    if(orientation == 1)
        return {{
            {EMPTY_CELL, L_CHAR, L_CHAR, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, L_CHAR, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, L_CHAR, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
        }};
    if(orientation == 2)
        return {{
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, L_CHAR},
            {EMPTY_CELL, L_CHAR, L_CHAR, L_CHAR},
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
        }};

    return {{
            {EMPTY_CELL, EMPTY_CELL, L_CHAR, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, L_CHAR, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, L_CHAR, L_CHAR},
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
        }};
}
