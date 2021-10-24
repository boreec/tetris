#include "Animator.hpp"

Tetris::gui::Animator::Animator(const std::vector<std::vector<std::pair<QPainterPath, QColor>>>& frames, const unsigned frameInterval):
    m_frames(frames),
    m_frameInterval(frameInterval)
{

}

const std::vector<std::vector<std::pair<QPainterPath, QColor>>>& Tetris::gui::Animator::getFrames() const{
    return m_frames;
}

unsigned Tetris::gui::Animator::getFrameInterval() const {
    return m_frameInterval;
}
