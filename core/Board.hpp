#pragma once

#include "Tetromino.hpp"
#include "TetrominoFactory.hpp"

#include <cassert>
#include <QColor>

namespace Tetris::core{

    /**
     * @brief Board represents the whole Tetris game area.
     */
    class Board{
    public:

        /**
         * @brief Board's constructor creates an empty Board.
         */
        Board();

        /**
         * @brief clear the whole board with empty cells.
         */
        void clear();

        /**
         * @brief eraseLines will remove the board's rows in a given range.
         * The lines that are above the erased lines will fall to give a
         * "gravity effect".
         * @param range is the range of rows to clear.
         */
        void eraseLines(const std::pair<int, int>& range);

        /**
         * @brief getBoard returns a reference to the Board.
         */
        const auto& getBoard() const;

        /**
         * @brief dropCurrentPiece will drop the current piece onto the Board.
         * the currentPiece handle will be set to nullptr aftwerward.
         */
        void dropCurrentPiece();

        /**
         * @brief isGameOver checks if the board spawn pieces anymore.
         * @return true if the board is in a game over state.
         */
        bool isGameOver() const;

        /**
         * @brief canMoveCurrentPieceDown
         * @return true if the piece can move downward.
         */
        bool canMoveCurrentPieceDown() const;

        /**
         * @brief canMoveCurrentPieceLeft
         * @return true if the piece can move leftward.
         */
        bool canMoveCurrentPieceLeft() const;

        /**
         * @brief canMoveCurrentPieceRight
         * @return true if the piece can move rightward.
         */
        bool canMoveCurrentPieceRight() const;

        /**
         * @brief canRotateCurrentPiece
         * @return true if the piece can rotate.
         */
        bool canRotateCurrentPiece() const;

        /**
         * @brief isWithinBoardWidth
         * @param x an integer to check
         * @return true if x is between 0 and board's width.
         */
        constexpr static bool isWithinBoardWidth(const int x);

        /**
         * @brief hasCompletedLines will check if there are lines full.
         * @return a pair of positive integers corresponding to the range of
         * completed lines, {0, 0} otherwise.
         */
        std::pair<int, int> hasCompletedLines() const;

        /**
         * @brief setCurrentPiece sets the given Tetromino piece as the current moving piece.
         * Board own the given Tetromino pointer.
         * @param t is the new Tetromino.
         */
        void setCurrentPiece(std::unique_ptr<Tetris::core::Tetromino> t);

        /**
         * @brief setNextPiece sets the given Tetromino piece as the next piece.
         * @param t is the Tetromino for the next piece.
         */
        void setNextPiece(std::unique_ptr<Tetris::core::Tetromino> t);

        /**
         * @brief swapPieces will replace currentPiece's content with nextPiece's content.
         * @param next is the new Tetromino for nextPiece.
         */
        void swapPieces(std::unique_ptr<Tetris::core::Tetromino> next);

        /**
         * @brief getCurrentPiece returns a pointer to the currentPiece (but still owns it).
         */
        Tetromino* getCurrentPiece();

        /**
         * @brief getNextPiece returns a pointer to the nextPiece (but still owns it).
         */
        Tetromino* getNextPiece();

        /**
         * @brief getCell returns the content of a board cell as a char.
         * @param x is the x axis coordinate of the cell.
         * @param y is the y axis coordinate of the cell.
         */
        char getCell(const int x, const int y) const;

        /**
         * @brief getCharColor returns a color for a specific character.
         * @param c is the character for which the color needs to be known.
         */
        static QColor getCharColor(const char c);

        /**
         * @brief m_height is the height of the board.
         */
        constexpr static int m_height = 22;

        /**
         * @brief m_width is the width of the board.
         */
        constexpr static int m_width = 10;

    private:

        /**
         * @brief m_board is the data structure representing the Tetris board.
         */
        std::array<std::array<char, m_width>, m_height> m_board;

        /**
         * @brief m_currentPiece corresponds to the current piece moving in the board.
         */
        std::unique_ptr<Tetris::core::Tetromino> m_currentPiece;

        /**
         * @brief m_nextPiece correspond to the next piece that will replace the current one.
         */
        std::unique_ptr<Tetris::core::Tetromino> m_nextPiece;
    };
}
