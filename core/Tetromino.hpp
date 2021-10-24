#pragma once

#include <array>

#define EMPTY_CELL '.'

namespace Tetris::core{
    /**
     * @brief Tetromino represents a basic Tetris piece.
     */
    class Tetromino{
    public:
        Tetromino();

        /**
         * @brief getChar
         * @return the char corresponding the piece.
         */
        virtual char getChar() const = 0;

        /**
         * @brief getPiece returns the matrix representation of the piece.
         * @param orientation is the matrix orientation.
         * @return the matrix of the piece.
         */
        virtual std::array<std::array<char,4>,4> getPiece(int orientation) const = 0;

        /**
         * @brief setX defines the new position on the x axis.
         * @param x is the new position.
         */
        void setX(const int x);

        /**
         * @brief setY defines the new position on the y axis.
         * @param y is the new position.
         */
        void setY(const int y);

        /**
         * @brief getX
         * @return the position on the x axis.
         */
        int getX() const;

        /**
         * @brief getY
         * @return the position on the y axis.
         */
        int getY() const;

        /**
         * @brief getOrientation
         * @return the orientation state.
         */
        int getOrientation() const;

        std::array<std::array<char,4>,4> getPiece() const;

        /**
         * @brief setOrientation defines the piece's rotation state
         * @param rotation is the rotation state and must be between 0 and 3 included.
         */
        void setOrientation(const int rotation);

    protected:

        /**
         * @brief m_x The piece's position on the x axis.
         */
        int m_x;

        /**
         * @brief m_y The piece's position on the y axis.
         */
        int m_y;

        /**
         * @brief m_orientation The piece orientation state.
         */
        int m_orientation;
    };
}
