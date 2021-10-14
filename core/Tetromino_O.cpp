#include "Tetromino_O.hpp"

Tetris::core::Tetromino_O::Tetromino_O()
{

}

char Tetris::core::Tetromino_O::getChar() const{
    return O_CHAR;
}

std::array<std::array<char,4>,4> Tetris::core::Tetromino_O::getPiece(int orientation) const{
    return {{
        {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
        {EMPTY_CELL, O_CHAR, O_CHAR, EMPTY_CELL},
        {EMPTY_CELL, O_CHAR, O_CHAR, EMPTY_CELL},
        {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
    }};
}
