#pragma once

#include "Tetromino.hpp"

#define O_CHAR 'O'

namespace Tetris{
    namespace core{
        class Tetromino_O : public Tetris::core::Tetromino{
        public:
            Tetromino_O();
            virtual char getChar() const override;
            virtual std::array<std::array<char,4>,4> getPiece(int orientation) const override;
        };
    }
}
