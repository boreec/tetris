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
        /**
         * @brief The TetrominoFactory generates Tetromino randomly.
         */
        class TetrominoFactory{
        public:

            /**
             * @brief TetrominoFactory's constructor is inexistant because
             * this is a static class.
             */
            TetrominoFactory() = delete;

            /**
             * @brief UniformPieceRandomizer generates a random piece, with
             * the same probability for every piece (uniform distribution).
             * @return a random Tetromino piece as a unique_ptr.
             */
            static std::unique_ptr<Tetris::core::Tetromino> UniformPieceRandomizer();

            /**
             * @brief BagPieceRandomizer generates a random piece with a bag approach.
             * Every piece is inserted into the bag once, and one is removed randomly
             * when a piece's needed. When the bag is empty, it is filled again.
             * @return a random Tetromino piece as a unique_ptr.
             */
            static std::unique_ptr<Tetris::core::Tetromino> BagPieceRandomizer();

        private:

            static std::vector<std::unique_ptr<Tetris::core::Tetromino>> m_bag;

            static std::random_device m_randomDevice;
            static std::mt19937 m_randomGenerator;
            static std::uniform_int_distribution<std::mt19937::result_type> m_orientationDist;
        };
    }
}
