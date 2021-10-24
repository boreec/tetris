#pragma once

#include <QColor>
#include <QPainterPath>

namespace Tetris::gui{
    /**
     * @brief The Frame class represents an Animation frame.
     */
    class Frame {
    public:
        /**
         * @brief Frame is the Frame's constructor.
         * @param painterPath is the shape of the frame.
         * @param timeInterval is the duration of the frame (0 by default).
         * @param color is the color of the Frame (black by default).
         */
        Frame(const QPainterPath& painterPath, const unsigned timeInterval = 0, const QColor& color = Qt::black);

        /**
         * @brief getFrameInterval returns the frame's duration.
         */
        unsigned getFrameInterval() const;

        /**
         * @brief getColor returns the frame's color.
         */
        QColor getColor() const;

        /**
         * @brief getPainterPath returns the frame's shape.
         */
        QPainterPath getPainterPath() const;

    protected:
        /**
         * @brief m_frameInterval is the frame's duration.
         */
        unsigned m_frameInterval;

        /**
         * @brief m_color is the frame's color.
         */
        QColor m_color;

        /**
         * @brief m_painterPath is the frame's shape.
         */
        QPainterPath m_painterPath;
    };
}

