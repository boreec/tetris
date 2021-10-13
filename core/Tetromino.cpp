#include "Tetromino.hpp"
#include <algorithm>
#include <iostream>
Tetromino::Tetromino():
    m_x(5),
    m_y(0),
    m_orientation(0)
{

}

void Tetromino::setX(const int x){
    m_x = x;
}

void Tetromino::setY(const int y){
    m_y = y;
}

int Tetromino::getX() const{
    return m_x;
}

int Tetromino::getY() const{
    return m_y;
}

int Tetromino::getOrientation() const{
    return m_orientation;
}

std::array<std::array<char,4>,4> Tetromino::getPiece() const{
    return getPiece(m_orientation);
}

void Tetromino::setOrientation(const int x){
    m_orientation = x;
}
