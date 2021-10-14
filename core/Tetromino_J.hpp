#pragma once

#include "Tetromino.hpp"

#define J_CHAR 'J'

namespace Tetris{
    namespace core{
        class Tetromino_J : public Tetris::core::Tetromino{
        public:
            Tetromino_J();
            virtual char getChar() const override;
            virtual std::array<std::array<char,4>,4> getPiece(int orientation) const override;
        };
    }
}
