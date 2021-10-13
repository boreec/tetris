#pragma once

#include "Tetromino.hpp"

#define Z_CHAR 'Z'

class Tetromino_Z : public Tetromino{
public:
    Tetromino_Z();
    virtual char getChar() const override;
    virtual std::array<std::array<char,4>,4> getPiece(int orientation) const override;
};

