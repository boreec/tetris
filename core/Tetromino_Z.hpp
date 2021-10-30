#pragma once

#include "Tetromino.hpp"

#define Z_CHAR 'Z'

namespace Tetris::core{

    /**
     * @brief The Tetromino_Z represents the Z Tetromino piece.
     * This piece is the mirror of Tetromino_S.
     */
    class Tetromino_Z : public Tetris::core::Tetromino{
    public:

        /**
         * @brief Tetromino_Z's constructor.
         */
        Tetromino_Z();

        /**
         * @brief getChar returns the char corresponding to a cell occupied by a Z piece.
         */
        char getChar() const override;

        /**
         * @brief getPiece returns the piece's matrix as 2d array of characters.
         * @param orientation specify the matrix's orientation.
         */
        std::array<std::array<char,4>,4> getPiece(int orientation) const override;
    };
}
