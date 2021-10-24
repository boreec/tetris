#pragma once

#include "Frame.hpp"

#include <QColor>
#include <QPainterPath>

#include <vector>

namespace Tetris::gui{
    class Animator{
    public:
        Animator(const std::vector<std::vector<Tetris::gui::Frame>>& frames);

        std::vector<std::vector<Tetris::gui::Frame>> getFrames() const;
    protected:
        std::vector<std::vector<Tetris::gui::Frame>> m_frames;
    };
}
