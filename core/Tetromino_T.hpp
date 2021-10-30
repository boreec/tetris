#pragma once

#include "Tetromino.hpp"

#define T_CHAR 'T'

namespace Tetris::core{

    /**
     * @brief Tetromino_T represents the T Tetromino piece.
     */
    class Tetromino_T : public Tetris::core::Tetromino{
    public:

        /**
         * @brief Tetromino_T's constructor.
         */
        Tetromino_T();

        /**
         * @brief getChar returns the char corresponding to a cell occupied by a T piece.
         */
        char getChar() const override;

        /**
         * @brief getPiece returns the piece's matrix as 2d array of characters.
         * @param orientation specify the matrix's orientation.
         */
        std::array<std::array<char,4>,4> getPiece(int orientation) const override;
    };
}
