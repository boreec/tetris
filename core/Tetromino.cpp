#include "Tetromino.hpp"
#include <algorithm>
#include <iostream>
Tetris::core::Tetromino::Tetromino():
    m_x(3),
    m_y(0),
    m_orientation(0)
{

}

void Tetris::core::Tetromino::setX(const int x){
    m_x = x;
}

void Tetris::core::Tetromino::setY(const int y){
    m_y = y;
}

int Tetris::core::Tetromino::getX() const{
    return m_x;
}

int Tetris::core::Tetromino::getY() const{
    return m_y;
}

int Tetris::core::Tetromino::getOrientation() const{
    return m_orientation;
}

std::array<std::array<char,4>,4> Tetris::core::Tetromino::getPiece() const{
    return getPiece(m_orientation);
}

void Tetris::core::Tetromino::setOrientation(const int x){
    m_orientation = x;
}
