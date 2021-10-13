#pragma once

#include "Tetromino.hpp"

#define O_CHAR 'O'

class Tetromino_O : public Tetromino{
public:
    Tetromino_O();
    virtual char getChar() const override;
    virtual std::array<std::array<char,4>,4> getPiece(int orientation) const override;
};
