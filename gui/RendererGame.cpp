#include "RendererGame.hpp"
#include <iostream>

RendererGame::RendererGame() :
    m_board(nullptr), m_gameOver(false)
{

}

void RendererGame::initializeGL(){
    //
}

void RendererGame::paintGL(){
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
                    drawBlock(painter, marginLeft + j * cellSize, i * cellSize, cellSize, m_board->getCharColor(m_board->getCell(j,i)));
                    //painter.fillRect(marginLeft + j * cellSize, i * cellSize, cellSize, cellSize, QBrush(m_board->getCharColor(m_board->getCell(j,i))));
                }else{
                    painter.setPen(Qt::blue);
                    painter.drawRect(marginLeft + j * cellSize, i * cellSize, cellSize, cellSize);
                }
            }
        }
    }
}

void RendererGame::drawBlock(QPainter& painter, const int x, const int y, const int blockSize, const QColor& colour){
    painter.fillRect(x, y, blockSize, blockSize, QBrush(colour));
    const int trapezoidHeight = blockSize / 4;
    // draw shiny edges
    if(trapezoidHeight > 0){
        QPainterPath topPath;
        topPath.lineTo(x, y);
        topPath.lineTo(x + blockSize,y);
        topPath.lineTo(x + blockSize - trapezoidHeight, y + trapezoidHeight);
        topPath.lineTo(x + trapezoidHeight, y + trapezoidHeight);
        topPath.lineTo(x, y);
        painter.fillPath(topPath, colour.lighter());

        QPainterPath leftPath;
        leftPath.lineTo(x,y);
        leftPath.lineTo(x + trapezoidHeight, y + trapezoidHeight);
        leftPath.lineTo(x + trapezoidHeight, y + blockSize - trapezoidHeight);
        leftPath.lineTo(x, y + blockSize);
        leftPath.lineTo(x,y);
        painter.fillPath(leftPath, colour.darker(200));

        QPainterPath rightPath;
        rightPath.lineTo(x + blockSize, y);
        rightPath.lineTo(x + blockSize - trapezoidHeight, y + trapezoidHeight);
        rightPath.lineTo(x + blockSize - trapezoidHeight, y + blockSize - trapezoidHeight);
        rightPath.lineTo(x + blockSize, y + blockSize);
        rightPath.lineTo(x + blockSize, y);
        painter.fillPath(rightPath, colour.darker(200));

        QPainterPath bottomPath;
        bottomPath.lineTo(x, y + blockSize);
        bottomPath.lineTo(x + blockSize, y + blockSize);
        bottomPath.lineTo(x + blockSize - trapezoidHeight, y + blockSize - trapezoidHeight);
        bottomPath.lineTo(x + trapezoidHeight, y + blockSize - trapezoidHeight);
        bottomPath.lineTo(x, y + blockSize);
        painter.fillPath(bottomPath, colour.darker(300));
    }
}

void RendererGame::drawGameOverScreen(){
    QPainter painter(this);
    painter.fillRect(0,0,this->width(), this->height(), QBrush(Qt::red));
    painter.setFont(QFont("Courier", 36, QFont::DemiBold));
    painter.drawText(0, 0, width(), height(), Qt::AlignCenter, "GAME OVER!");
    painter.end();
}

void RendererGame::resizeGL(int w, int h){
    glViewport(0, 0, w, h);
}

void RendererGame::setBoard(Board *board){
    m_board = board;
}

void RendererGame::setGameOver(bool b){
    m_gameOver = b;
}
