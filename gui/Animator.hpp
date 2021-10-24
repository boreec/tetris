#pragma once

#include <QColor>
#include <QPainterPath>

#include <vector>

namespace Tetris::gui{
    class Animator{
    public:
        Animator(const std::vector<std::vector<std::pair<QPainterPath, QColor>>>& frames, const unsigned frameInterval);

        unsigned getFrameInterval() const;

        const std::vector<std::vector<std::pair<QPainterPath, QColor>>>& getFrames() const;
    protected:
        std::vector<std::vector<std::pair<QPainterPath, QColor>>> m_frames;
        unsigned m_frameInterval;
    };
}
