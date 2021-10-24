#include "Animator.hpp"

Tetris::gui::Animator::Animator(const std::vector<std::vector<Tetris::gui::Frame>>& frames):
    m_frames(frames)
{

}

std::vector<std::vector<Tetris::gui::Frame>> Tetris::gui::Animator::getFrames() const{
    return m_frames;
}
