#pragma once

#include "Tetromino.hpp"

#define L_CHAR 'L'

namespace Tetris::core{

    /**
    * @brief The Tetromino_L represents the L Tetromino piece.
    * This piece is the mirror of Tetromino_J.
    */
    class Tetromino_L : public Tetris::core::Tetromino {
    public:

        /**
         * @brief Tetromino_L's constructor.
         */
        Tetromino_L();

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
