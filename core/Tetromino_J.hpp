#pragma once

#include "Tetromino.hpp"

#define J_CHAR 'J'

namespace Tetris::core{

    /**
    * @brief The Tetromino_J represents the J Tetromino piece.
    * This piece is the mirror of Tetromino_L.
    */
    class Tetromino_J : public Tetris::core::Tetromino{
    public:

        /**
         * @brief Tetromino_J's constructor.
         */
        Tetromino_J();

        /**
         * @brief getChar returns the char corresponding to a cell occupied by a J piece.
         */
        char getChar() const override;

        /**
         * @brief getPiece returns the piece's matrix as 2d array of characters.
         * @param orientation specify the matrix's orientation.
         */
        std::array<std::array<char,4>,4> getPiece(int orientation) const override;
    };
}
