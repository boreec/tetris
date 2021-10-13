#pragma once

#include <array>

#define EMPTY_CELL '.'

class Tetromino{
public:
    Tetromino();
    virtual char getChar() const = 0;
    virtual std::array<std::array<char,4>,4> getPiece(int orientation) const = 0;
    void setX(const int x);

    void setY(const int y);

    int getX() const;

    int getY() const;

    int getOrientation() const;

    std::array<std::array<char,4>,4> getPiece() const;

    void setOrientation(const int);
protected:

    int m_x;

    int m_y;

    int m_orientation;
};
