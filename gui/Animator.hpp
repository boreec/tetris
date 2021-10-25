#pragma once

#include "Frame.hpp"

#include <QColor>
#include <QPainterPath>

#include <vector>

namespace Tetris::gui{

    /**
     * @brief The Animator represents an animation of @class Frame.
     */
    class Animation{
    public:

        /**
         * @brief Animator is the Animator's constructor.
         * @param frames is a vector of a vector of frames.
         * It is organized sequentially frames[0] is the first vector containing the
         * frames to display at first, frames[1] contains the next vector of frames
         * to display afterward to complete the animation.
         */
        Animation(const std::vector<Tetris::gui::Frame>& frames);

        /**
         * @brief getFrames returns the animation's frames.
         */
        std::vector<Tetris::gui::Frame> getFrames() const;
    protected:

        /**
         * @brief m_frames corresponds to the animation's frame.
         */
        std::vector<Tetris::gui::Frame> m_frames;
    };
}
