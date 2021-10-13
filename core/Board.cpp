#include "Board.hpp"
#include <iostream>

Board::Board(){
    clear();
}

void Board::clear(){
    // Put a '.' char in every board's cell to represent emptiness.
    for(int i = 0; i < HEIGHT; ++i){
        std::fill(m_board[i].begin(), m_board[i].end(), EMPTY_CELL);
    }
}

int Board::getHeight() const{
    return HEIGHT;
}

int Board::getWidth() const{
    return WIDTH;
}

std::array<std::array<char, BOARD_WIDTH>, BOARD_HEIGHT> Board::getBoard() const{
    return m_board;
}

bool Board::isWithinBoardWidth(const int x) const{
    return x >= 0 && x < BOARD_WIDTH;
}

bool Board::canMoveCurrentPieceDown(){
    bool canMoveDown = true;
    int row_idx, row_start;
    int col_idx = 0;
    while(col_idx < 4 && canMoveDown){
        row_idx = 3, row_start = -1;
        while(row_idx >= 0 && row_start == -1){
            row_start = m_currentPiece->getPiece()[row_idx][col_idx] != EMPTY_CELL ? row_idx : -1;
            --row_idx;
        }
        if(row_start != -1){
            canMoveDown = m_currentPiece->getY() + row_start + 1 < BOARD_HEIGHT && m_board[m_currentPiece->getY() + row_start + 1][m_currentPiece->getX() + col_idx] == EMPTY_CELL;
        }
        col_idx++;
    }
    return canMoveDown;
}

bool Board::canMoveCurrentPieceLeft(){
    bool canMoveLeft = true;
    int col_idx, col_start;
    int row_idx = 0;
    while(row_idx < 4 && canMoveLeft){
        col_idx = 0, col_start = -1;
        while(col_idx < 4 && col_start == -1){
            col_start = m_currentPiece->getPiece()[row_idx][col_idx] != EMPTY_CELL ? col_idx : -1;
            ++col_idx;
        }
        if(col_start != -1){
            canMoveLeft = m_currentPiece->getX() + col_start - 1 >= 0 && m_board[m_currentPiece->getY() + row_idx][m_currentPiece->getX() + col_start - 1] == EMPTY_CELL;
        }
        row_idx++;
    }
    return canMoveLeft;
}

bool Board::canMoveCurrentPieceRight(){
    bool canMoveRight = true;
    int col_idx, col_start;
    int row_idx = 0;
    while(row_idx < 4 && canMoveRight){
        col_idx = 3, col_start = -1;
        while(col_idx > 0 && col_start == -1){
            col_start = m_currentPiece->getPiece()[row_idx][col_idx] != EMPTY_CELL ? col_idx : -1;
            col_idx--;
        }
        if(col_start != -1){
            canMoveRight = m_currentPiece->getX() + col_start + 1 < BOARD_WIDTH && m_board[m_currentPiece->getY() + row_idx][m_currentPiece->getX() + col_start + 1] == EMPTY_CELL;
        }
        row_idx++;
    }
    return canMoveRight;
}

bool Board::canRotateCurrentPiece(){
    bool canRotate = true;
    int row_idx = 0, col_idx;
    while(row_idx < 4 && canRotate){
        col_idx = 0;
        while(col_idx < 4 && canRotate){
            canRotate = isWithinBoardWidth(m_currentPiece->getX() + col_idx);
            col_idx++;
        }
        row_idx++;
    }
    return canRotate;
}
void Board::dropCurrentPiece(){
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            if(isWithinBoardWidth(m_currentPiece->getX() + j) &&
                    m_currentPiece->getY() + i >= 0 &&
                    m_currentPiece->getY() + i - 1 < BOARD_HEIGHT &&
                    m_currentPiece->getPiece()[i][j] != EMPTY_CELL){
                m_board[m_currentPiece->getY() + i][m_currentPiece->getX() + j] = m_currentPiece->getPiece()[i][j];
            }
        }
    }
}

bool Board::isGameOver() const{
    bool overlap = false;
    int row_idx = 0;
    while(row_idx < 4 && !overlap){
        int col_idx = 0;
        while(col_idx < 4 && !overlap){
            overlap = (isWithinBoardWidth(m_currentPiece->getX() + col_idx) &&
                       m_currentPiece->getY() + row_idx >= 0 && m_currentPiece->getY() + row_idx < BOARD_HEIGHT) ?
                       m_board[m_currentPiece->getY() + row_idx][m_currentPiece->getX() + col_idx] != EMPTY_CELL : false;
            ++col_idx;
        }
        ++row_idx;
    }
    return overlap;
}

int Board::removeCompletedLines(){
    int completedLines = 0;
    int rowStart= -1;
    int row_idx = 0;
    while(row_idx < BOARD_HEIGHT){
        int col_idx = 0;
        while(col_idx < BOARD_WIDTH && m_board[row_idx][col_idx] != EMPTY_CELL){
            ++col_idx;
        }
        //line filled!
        if(col_idx >= BOARD_WIDTH){
            rowStart = !completedLines ? row_idx : rowStart;
            ++completedLines;
        }
        ++row_idx;
    }
    // clear lines by overwritting with above
    if(completedLines){
        assert(completedLines >= 1 && completedLines <= 4);
        for(int i = rowStart + completedLines - 1; i > completedLines; --i){
            if(i <= completedLines){
                for(int j = 0; j < BOARD_WIDTH; ++j){m_board[i][j] = EMPTY_CELL;}
                continue;
            }for(int j = 0; j < BOARD_WIDTH; ++j){
                m_board[i][j] = m_board[i - completedLines][j];
            }
        }
    }
    return completedLines;
}

void Board::setCurrentPiece(Tetromino *t){
    m_currentPiece = t;
}

void Board::setNextPiece(Tetromino *t){
    m_nextPiece = t;
}

Tetromino* Board::getCurrentPiece(){
    return m_currentPiece;
}

Tetromino* Board::getNextPiece(){
    return m_nextPiece;
}

char Board::getCell(const int x, const int y) const{
    char c = m_board[y][x];
    if(x >= m_currentPiece->getX() && x < m_currentPiece->getX() + 4 &&
       y >= m_currentPiece->getY() && y < m_currentPiece->getY() + 4 ){
        c = m_currentPiece->getPiece()[y - m_currentPiece->getY()][x -  m_currentPiece->getX()];
        if(c == EMPTY_CELL)
            c = m_board[y][x];
    }
    return c;
}

QColor Board::getCharColor(const char c){
    switch(c){
        case EMPTY_CELL: return Qt::black;
        case I_CHAR: return Qt::cyan;
        case J_CHAR: return Qt::darkBlue;
        case L_CHAR: return QColor(255,140,0);
        case O_CHAR: return Qt::yellow;
        case S_CHAR: return Qt::green;
        case T_CHAR: return Qt::magenta;
        case Z_CHAR: return Qt::red;
        default: return Qt::black;
    }
}
