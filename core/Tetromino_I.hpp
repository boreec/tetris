#pragma once

#include "Tetromino.hpp"

#define I_CHAR 'I'

namespace Tetris::core{

    /**
     * @brief The Tetromino_I represents the I Tetromino piece.
     */
    class Tetromino_I : public Tetris::core::Tetromino{
    public:

        /**
         * @brief Tetromino_I's constructor.
         */
        Tetromino_I();

        /**
         * @brief getChar returns the char corresponding to a cell occupied by a I piece.
         */
        char getChar() const override;

        /**
         * @brief getPiece returns the piece's matrix as 2d array of characters.
         * @param orientation specify the matrix's orientation.
         */
        std::array<std::array<char,4>,4> getPiece(int orientation) const override;
    };
}
