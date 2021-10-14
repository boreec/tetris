#include "Tetromino_J.hpp"

Tetris::core::Tetromino_J::Tetromino_J()
{

}
char Tetris::core::Tetromino_J::getChar() const{
    return J_CHAR;
}

std::array<std::array<char,4>,4> Tetris::core::Tetromino_J::getPiece(int orientation) const{
    if(!orientation)
        return {{
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
            {EMPTY_CELL, J_CHAR, J_CHAR, J_CHAR},
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, J_CHAR},
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
        }};
    if(orientation == 1)
        return {{
            {EMPTY_CELL, EMPTY_CELL, J_CHAR, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, J_CHAR, EMPTY_CELL},
            {EMPTY_CELL, J_CHAR, J_CHAR, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
        }};
    if(orientation == 2)
        return {{
            {EMPTY_CELL, J_CHAR, EMPTY_CELL, EMPTY_CELL},
            {EMPTY_CELL, J_CHAR, J_CHAR, J_CHAR},
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
        }};

    return {{
            {EMPTY_CELL, EMPTY_CELL, J_CHAR, J_CHAR},
            {EMPTY_CELL, EMPTY_CELL, J_CHAR, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, J_CHAR, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
        }};
}
