#pragma once

#include "Tetromino.hpp"

#define I_CHAR 'I'

class Tetromino_I : public Tetromino{
public:
    Tetromino_I();
    virtual char getChar() const override;
    virtual std::array<std::array<char,4>,4> getPiece(int orientation) const override;
};
