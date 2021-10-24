#pragma once

#include <QColor>
#include <QPainterPath>

namespace Tetris::gui{
    class Frame {
    public:
        Frame(const QPainterPath& painterPath, const unsigned timeInterval = 0, const QColor& color = Qt::black);
    protected:
        unsigned m_frameInterval;
        QColor m_color;
        QPainterPath m_painterPath;
    };
}

