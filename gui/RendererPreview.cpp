#include "RendererPreview.hpp"

Tetris::gui::RendererPreview::RendererPreview(Tetris::core::Tetromino* tetromino) :
    m_tetromino(tetromino)
{

}

/*
 * Called once before paintGL() or resizeGL().
 * Set up any required OpenGL resources and state.
 * */
void Tetris::gui::RendererPreview::initializeGL(){

}

/*
 * Renders the OpenGL scene. Gets called whenever
 * the widget needs to be updated.
 * */
void Tetris::gui::RendererPreview::paintGL(){

    QPainter painter(this);

    painter.setPen(Qt::black);
    painter.fillRect(0,0, this->width(), this->height(),QBrush(Qt::black));
    int cellSize = this->height() / 4;
    int marginLeft = (this->width() - 4 * cellSize) / 2;

    if(m_tetromino){
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 4; ++j){
                if(m_tetromino->getPiece()[i][j] != EMPTY_CELL){
                    Tetris::gui::RendererFacilities::drawBlock(painter, marginLeft + j * cellSize, i * cellSize, cellSize, Tetris::core::Board::getCharColor((m_tetromino->getChar())));
                }else{
                    painter.setPen(Qt::black);
                    painter.drawRect(marginLeft + j * cellSize, i * cellSize, cellSize, cellSize);
                }
            }
        }
    }
}

/*
 * Called whenever the widget has been resized.
 * */
void Tetris::gui::RendererPreview::resizeGL(int w, int h){

}

void Tetris::gui::RendererPreview::setTetromino(Tetris::core::Tetromino *tetromino){
    m_tetromino = tetromino;
}
