#include "Board.hpp"

Tetris::core::Board::Board(){
    clear();
}

void Tetris::core::Board::clear(){
    // Put a '.' char in every board's cell to represent emptiness.
    for(int i = 0; i < m_height; ++i){
       std::fill(m_board[i].begin(), m_board[i].end(), EMPTY_CELL);
    }
}

void Tetris::core::Board::eraseLines(const std::pair<int, int>& range){
    int completedLines = range.second - range.first;
    for(int i = range.first + completedLines - 1; i > completedLines; --i){
        if(i <= completedLines){
            for(int j = 0; j < m_width; ++j){m_board[i][j] = EMPTY_CELL;}
            continue;
        }for(int j = 0; j < m_width; ++j){
            m_board[i][j] = m_board[i - completedLines][j];
        }
    }
}


const auto& Tetris::core::Board::getBoard() const{
    return m_board;
}

constexpr bool Tetris::core::Board::isWithinBoardWidth(const int x){
    return x >= 0 && x < m_width;
}

bool Tetris::core::Board::canMoveCurrentPieceDown() const{
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
            canMoveDown = m_currentPiece->getY() + row_start + 1 < m_height && m_board[m_currentPiece->getY() + row_start + 1][m_currentPiece->getX() + col_idx] == EMPTY_CELL;
        }
        col_idx++;
    }
    return canMoveDown;
}

bool Tetris::core::Board::canMoveCurrentPieceLeft() const{
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

bool Tetris::core::Board::canMoveCurrentPieceRight() const{
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
            canMoveRight = m_currentPiece->getX() + col_start + 1 < m_width && m_board[m_currentPiece->getY() + row_idx][m_currentPiece->getX() + col_start + 1] == EMPTY_CELL;
        }
        row_idx++;
    }
    return canMoveRight;
}

bool Tetris::core::Board::canRotateCurrentPiece() const{
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

void Tetris::core::Board::dropCurrentPiece(){
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            if(isWithinBoardWidth(m_currentPiece->getX() + j) &&
                    m_currentPiece->getY() + i >= 0 &&
                    m_currentPiece->getY() + i - 1 < m_height &&
                    m_currentPiece->getPiece()[i][j] != EMPTY_CELL){
                m_board[m_currentPiece->getY() + i][m_currentPiece->getX() + j] = m_currentPiece->getPiece()[i][j];
            }
        }
    }
}

bool Tetris::core::Board::isGameOver() const{
    bool overlap = false;
    int row_idx = 0;
    while(row_idx < 4 && !overlap){
        int col_idx = 0;
        while(col_idx < 4 && !overlap){
            overlap = (isWithinBoardWidth(m_currentPiece->getX() + col_idx) &&
                       m_currentPiece->getY() + row_idx >= 0 && m_currentPiece->getY() + row_idx < m_height) ?
                       m_board[m_currentPiece->getY() + row_idx][m_currentPiece->getX() + col_idx] != EMPTY_CELL : false;
            ++col_idx;
        }
        ++row_idx;
    }
    return overlap;
}

std::pair<int, int> Tetris::core::Board::hasCompletedLines() const{
    int completeLines = 0;
    int completeBegin = 0;
    for(int row_idx = 0; row_idx < m_height; ++row_idx){
        auto it = std::find(m_board[row_idx].begin(), m_board[row_idx].end(), EMPTY_CELL);
        if(it == m_board[row_idx].end()){ // line complete
            completeBegin = !completeLines ? row_idx : completeBegin;
            ++completeLines;
        }else{
            continue;
        }
    }
    return completeLines ? std::pair<int, int>(completeBegin, completeBegin+completeLines) : std::pair<int, int>(0,0);
}

void Tetris::core::Board::setCurrentPiece(std::unique_ptr<Tetris::core::Tetromino> t){
    m_currentPiece = std::move(t);
}

void Tetris::core::Board::setNextPiece(std::unique_ptr<Tetromino> t){
    m_nextPiece = std::move(t);
}

Tetris::core::Tetromino* Tetris::core::Board::getCurrentPiece(){
    return m_currentPiece.get();
}

Tetris::core::Tetromino* Tetris::core::Board::getNextPiece(){
    return m_nextPiece.get();
}

void Tetris::core::Board::swapPieces(std::unique_ptr<Tetris::core::Tetromino> next){
    m_currentPiece = std::move(m_nextPiece);
    m_nextPiece = std::move(next);
}

char Tetris::core::Board::getCell(const int x, const int y) const{
    char c = m_board[y][x];
    if(x >= m_currentPiece->getX() && x < m_currentPiece->getX() + 4 &&
       y >= m_currentPiece->getY() && y < m_currentPiece->getY() + 4 ){
        c = m_currentPiece->getPiece()[y - m_currentPiece->getY()][x -  m_currentPiece->getX()];
        if(c == EMPTY_CELL)
            c = m_board[y][x];
    }
    return c;
}

QColor Tetris::core::Board::getCharColor(const char c){
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
