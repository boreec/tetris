#include "Frame.hpp"

Tetris::gui::Frame::Frame(const QPainterPath& painterPath, const unsigned frameInterval, const QColor& color):
    m_painterPath(painterPath),
    m_frameInterval(frameInterval),
    m_color(color)
{

}
