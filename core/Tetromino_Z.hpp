#pragma once

#include "Tetromino.hpp"

#define Z_CHAR 'Z'

namespace Tetris::core{
    class Tetromino_Z : public Tetris::core::Tetromino{
    public:
        Tetromino_Z();
        char getChar() const override;
        std::array<std::array<char,4>,4> getPiece(int orientation) const override;
    };
}
