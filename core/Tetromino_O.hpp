#pragma once

#include "Tetromino.hpp"

#define O_CHAR 'O'

namespace Tetris::core{

    /**
    * @brief The Tetromino_O represents the O Tetromino piece.
    */
    class Tetromino_O : public Tetris::core::Tetromino{
    public:

        /**
         * @brief Tetromino_O's constructor.
         */
        Tetromino_O();

        /**
         * @brief getChar returns the char corresponding to a cell occupied by a O piece.
         */
        char getChar() const override;

        /**
         * @brief getPiece returns the piece's matrix as 2d array of characters.
         * @param orientation specify the matrix's orientation.
         */
        std::array<std::array<char,4>,4> getPiece(int orientation) const override;
    };
}
