#pragma once

#include "Tetromino.hpp"

#define S_CHAR 'S'

namespace Tetris::core{

    /**
    * @brief The Tetromino_S represents the S Tetromino piece.
    * This piece is the mirror of Tetromino_Z.
    */
    class Tetromino_S : public Tetris::core::Tetromino{
    public:

        /**
         * @brief Tetromino_S's constructor.
         */
        Tetromino_S();

        /**
         * @brief getChar returns the char corresponding to a cell occupied by a S piece.
         */
        char getChar() const override;

        /**
         * @brief getPiece returns the piece's matrix as 2d array of characters.
         * @param orientation specify the matrix's orientation.
         */
        std::array<std::array<char,4>,4> getPiece(int orientation) const override;
    };
}

