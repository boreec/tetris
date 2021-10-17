#include "RendererFacilities.hpp"

void Tetris::gui::RendererFacilities::drawBlock(QPainter& painter, const int x, const int y, const int blockSize, const QColor& colour){
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
