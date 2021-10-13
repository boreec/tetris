#pragma once

#include "Tetromino.hpp"

#define S_CHAR 'S'

class Tetromino_S : public Tetromino{
public:
    Tetromino_S();
    virtual char getChar() const override;
    virtual std::array<std::array<char,4>,4> getPiece(int orientation) const override;
};

