#include "Frame.hpp"

Tetris::gui::Frame::Frame(const QPainterPath& painterPath, const unsigned frameInterval, const QColor& color):
    m_painterPath(painterPath),
    m_frameInterval(frameInterval),
    m_color(color)
{

}

unsigned Tetris::gui::Frame::getFrameInterval() const{
    return m_frameInterval;
}

QColor Tetris::gui::Frame::getColor() const{
    return m_color;
}

QPainterPath Tetris::gui::Frame::getPainterPath() const{
    return m_painterPath;
}
