#pragma once

#include "Tetromino.hpp"

#define T_CHAR 'T'

class Tetromino_T : public Tetromino{
public:
    Tetromino_T();
    virtual char getChar() const override;
    virtual std::array<std::array<char,4>,4> getPiece(int orientation) const override;
};
