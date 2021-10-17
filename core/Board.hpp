#pragma once

#include "Tetromino.hpp"
#include "TetrominoFactory.hpp"

#include <cassert>
#include <QColor>

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 22

namespace Tetris{
    namespace core{
        class Board{
        public:
            Board();
            void spawnPiece(Tetromino* t);
            void clear();

            const auto& getBoard() const;
            void dropCurrentPiece();
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
            bool isWithinBoardWidth(const int x) const;
            int removeCompletedLines();
            void setCurrentPiece(std::unique_ptr<Tetris::core::Tetromino> t);
            void setNextPiece(std::unique_ptr<Tetris::core::Tetromino> t);

            // swap next piece with current piece and set new tetromino for current piece.
            void swapPieces(std::unique_ptr<Tetris::core::Tetromino> next);
            Tetromino* getCurrentPiece();
            Tetromino* getNextPiece();
            char getCell(const int x, const int y) const;
            static QColor getCharColor(const char c);

            constexpr static int m_height = 22;
            constexpr static int m_width = 10;
        private:
            std::array<std::array<char, m_width>, m_height> m_board;

            std::unique_ptr<Tetris::core::Tetromino> m_currentPiece;
            std::unique_ptr<Tetris::core::Tetromino> m_nextPiece;
        };
    }
}
