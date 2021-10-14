#include "Tetromino_Z.hpp"

Tetris::core::Tetromino_Z::Tetromino_Z()
{

}

char Tetris::core::Tetromino_Z::getChar() const{
    return Z_CHAR;
}

std::array<std::array<char,4>,4> Tetris::core::Tetromino_Z::getPiece(int orientation) const{
    if(!(orientation % 2))
        return {{
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
            {EMPTY_CELL, Z_CHAR, Z_CHAR, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, Z_CHAR, Z_CHAR},
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
        }};
    return {{
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, Z_CHAR},
            {EMPTY_CELL, EMPTY_CELL, Z_CHAR, Z_CHAR},
            {EMPTY_CELL, EMPTY_CELL, Z_CHAR, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
        }};
}
