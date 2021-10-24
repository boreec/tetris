#include "Animator.hpp"

Tetris::gui::Animator::Animator(const std::vector<Tetris::gui::Frame>& frames):
    m_frames(frames)
{

}

std::vector<Tetris::gui::Frame> Tetris::gui::Animator::getFrames() const{
    return m_frames;
}
