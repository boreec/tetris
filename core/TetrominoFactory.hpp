#pragma once

#include <algorithm>
#include <memory>
#include <random>

#include "Tetromino.hpp"
#include "Tetromino_I.hpp"
#include "Tetromino_J.hpp"
#include "Tetromino_L.hpp"
#include "Tetromino_O.hpp"
#include "Tetromino_S.hpp"
#include "Tetromino_T.hpp"
#include "Tetromino_Z.hpp"

namespace Tetris{
    namespace core{
        class TetrominoFactory{
        public:
            TetrominoFactory();

            static std::unique_ptr<Tetris::core::Tetromino> generateRandomTetromino();
        };
    }
}
