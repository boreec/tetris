#pragma once

#include "Tetromino.hpp"

#define T_CHAR 'T'

namespace Tetris::core{
    class Tetromino_T : public Tetris::core::Tetromino{
    public:
        Tetromino_T();
        char getChar() const override;
        std::array<std::array<char,4>,4> getPiece(int orientation) const override;
    };
}
