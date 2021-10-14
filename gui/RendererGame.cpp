#include "RendererGame.hpp"
#include <iostream>

Tetris::gui::RendererGame::RendererGame() :
    m_board(nullptr), m_gameOver(false)
{

}

void Tetris::gui::RendererGame::initializeGL(){
    //
}

void Tetris::gui::RendererGame::paintGL(){
    if(m_gameOver){
        drawGameOverScreen();
        return;
    }
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.fillRect(0,0,this->width(), this->height(),QBrush(Qt::black));
    if(m_board){
        int cellSize = this->height() / m_board->getHeight();
        int marginLeft = (this->width() - m_board->getWidth() * cellSize) / 2;
        for(int i = 0; i < m_board->getHeight(); ++i){
            for(int j = 0; j < m_board->getWidth(); ++j){
                if(m_board->getCell(j,i) != EMPTY_CELL){
                    Tetris::gui::RendererFacilities::drawBlock(painter, marginLeft + j * cellSize, i * cellSize, cellSize, m_board->getCharColor(m_board->getCell(j,i)));
                }else{
                    painter.setPen(Qt::blue);
                    painter.drawRect(marginLeft + j * cellSize, i * cellSize, cellSize, cellSize);
                }
            }
        }
    }
}

void Tetris::gui::RendererGame::drawGameOverScreen(){
    QPainter painter(this);
    painter.fillRect(0,0,this->width(), this->height(), QBrush(Qt::red));
    painter.setFont(QFont("Courier", 36, QFont::DemiBold));
    painter.drawText(0, 0, width(), height(), Qt::AlignCenter, "GAME OVER!");
    painter.end();
}

void Tetris::gui::RendererGame::resizeGL(int w, int h){
    glViewport(0, 0, w, h);
}

void Tetris::gui::RendererGame::setBoard(Tetris::core::Board *board){
    m_board = board;
}

void Tetris::gui::RendererGame::setGameOver(bool b){
    m_gameOver = b;
}
