#pragma once

#include <algorithm>
#include <random>

#include "Tetromino.hpp"
#include "Tetromino_I.hpp"
#include "Tetromino_J.hpp"
#include "Tetromino_L.hpp"
#include "Tetromino_O.hpp"
#include "Tetromino_S.hpp"
#include "Tetromino_T.hpp"
#include "Tetromino_Z.hpp"

class TetrominoFactory{
public:
    TetrominoFactory();

    static Tetromino* generateRandomTetromino();
};
