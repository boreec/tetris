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
            TetrominoFactory()=delete;

            static std::unique_ptr<Tetris::core::Tetromino> UniformPieceRandomizer();

            static std::unique_ptr<Tetris::core::Tetromino> BagPieceRandomizer();

        private:

            static std::vector<std::unique_ptr<Tetris::core::Tetromino>> m_bag;

            static std::random_device m_randomDevice;
            static std::mt19937 m_randomGenerator;
            static std::uniform_int_distribution<std::mt19937::result_type> m_orientationDist;
        };
    }
}
