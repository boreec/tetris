#pragma once

#include "Tetromino.hpp"

#define J_CHAR 'J'

namespace Tetris{
    namespace core{
        class Tetromino_J : public Tetris::core::Tetromino{
        public:
            Tetromino_J();
            char getChar() const override;
            std::array<std::array<char,4>,4> getPiece(int orientation) const override;
        };
    }
}
