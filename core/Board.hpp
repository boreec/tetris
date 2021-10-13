#pragma once

#include "Tetromino.hpp"
#include "TetrominoFactory.hpp"

#include <cassert>
#include <QColor>

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 22

class Board{
public:
    Board();
    int getHeight() const;
    int getWidth() const;
    void spawnPiece(Tetromino* t);
    void clear();

    std::array<std::array<char, BOARD_WIDTH>, BOARD_HEIGHT> getBoard() const;
    void dropCurrentPiece();
    bool isGameOver() const;
    bool canMoveCurrentPieceDown();
    bool canMoveCurrentPieceLeft();
    bool canMoveCurrentPieceRight();
    bool canRotateCurrentPiece();
    bool isWithinBoardWidth(const int x) const;
    int removeCompletedLines();
    void setCurrentPiece(Tetromino* t);
    void setNextPiece(Tetromino* t);
    Tetromino* getCurrentPiece();
    Tetromino* getNextPiece();
    char getCell(const int x, const int y) const;
    static QColor getCharColor(const char c);
private:
    const static int HEIGHT = BOARD_HEIGHT;
    const static int WIDTH = BOARD_WIDTH;
    std::array<std::array<char, BOARD_WIDTH>, BOARD_HEIGHT> m_board;

    Tetromino* m_currentPiece;
    Tetromino* m_nextPiece;
};
