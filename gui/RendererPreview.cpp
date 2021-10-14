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
                    drawBlock(painter, marginLeft + j * cellSize, i * cellSize, cellSize, Tetris::core::Board::getCharColor((m_tetromino->getChar())));
                }else{
                    painter.setPen(Qt::black);
                    painter.drawRect(marginLeft + j * cellSize, i * cellSize, cellSize, cellSize);
                }
            }
        }
    }
}

void Tetris::gui::RendererPreview::drawBlock(QPainter& painter, const int x, const int y, const int blockSize, const QColor& colour){
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

/*
 * Called whenever the widget has been resized.
 * */
void Tetris::gui::RendererPreview::resizeGL(int w, int h){

}

void Tetris::gui::RendererPreview::setTetromino(Tetris::core::Tetromino *tetromino){
    m_tetromino = tetromino;
}
