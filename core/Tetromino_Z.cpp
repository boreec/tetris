#include "Tetromino_Z.hpp"

Tetromino_Z::Tetromino_Z()
{

}

char Tetromino_Z::getChar() const{
    return Z_CHAR;
}

std::array<std::array<char,4>,4> Tetromino_Z::getPiece(int orientation) const{
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
