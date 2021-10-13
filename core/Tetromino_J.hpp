#pragma once

#include "Tetromino.hpp"

#define J_CHAR 'J'
class Tetromino_J : public Tetromino
{
public:
    Tetromino_J();
    virtual char getChar() const override;
    virtual std::array<std::array<char,4>,4> getPiece(int orientation) const override;
};

