#pragma once

#include "Tetromino.hpp"

#define L_CHAR 'L'

namespace Tetris{
    namespace core{
        class Tetromino_L : public Tetris::core::Tetromino {
        public:
            Tetromino_L();
            virtual char getChar() const override;
            virtual std::array<std::array<char,4>,4> getPiece(int orientation) const override;
        };
    }
}
