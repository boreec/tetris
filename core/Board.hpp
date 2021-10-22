#pragma once

#include "Tetromino.hpp"
#include "TetrominoFactory.hpp"

#include <cassert>
#include <QColor>

namespace Tetris{
    namespace core{

        /**
         * @brief Board represents the whole Tetris game area.
         */
        class Board{
        public:
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

            const auto& getBoard() const;
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
             * @class Board will own the given Tetromino pointer.
             * @param t is the new Tetromino.
             */
            void setCurrentPiece(std::unique_ptr<Tetris::core::Tetromino> t);
            void setNextPiece(std::unique_ptr<Tetris::core::Tetromino> t);

            // swap next piece with current piece and set new tetromino for current piece.
            void swapPieces(std::unique_ptr<Tetris::core::Tetromino> next);
            Tetromino* getCurrentPiece();
            Tetromino* getNextPiece();
            char getCell(const int x, const int y) const;
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
}
