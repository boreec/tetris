#include "Tetromino_T.hpp"

Tetris::core::Tetromino_T::Tetromino_T()
{

}

char Tetris::core::Tetromino_T::getChar() const{
    return T_CHAR;
}

std::array<std::array<char,4>,4> Tetris::core::Tetromino_T::getPiece(int orientation) const{
    if(!orientation)
        return {{
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
            {EMPTY_CELL, T_CHAR, T_CHAR, T_CHAR},
            {EMPTY_CELL, EMPTY_CELL, T_CHAR, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
        }};
    if(orientation == 1)
        return {{
            {EMPTY_CELL, EMPTY_CELL, T_CHAR, EMPTY_CELL},
            {EMPTY_CELL, T_CHAR, T_CHAR, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, T_CHAR, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
        }};
    if(orientation == 2)
        return {{
            {EMPTY_CELL, EMPTY_CELL, T_CHAR, EMPTY_CELL},
            {EMPTY_CELL, T_CHAR, T_CHAR, T_CHAR},
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
        }};
    return {{
        {EMPTY_CELL, EMPTY_CELL, T_CHAR, EMPTY_CELL},
        {EMPTY_CELL, EMPTY_CELL, T_CHAR, T_CHAR},
        {EMPTY_CELL, EMPTY_CELL, T_CHAR, EMPTY_CELL},
        {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
    }};
}

