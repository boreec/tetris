#include "Animator.hpp"

Tetris::gui::Animation::Animation(const std::vector<Tetris::gui::Frame>& frames):
    m_frames(frames)
{

}

std::vector<Tetris::gui::Frame> Tetris::gui::Animation::getFrames() const{
    return m_frames;
}
