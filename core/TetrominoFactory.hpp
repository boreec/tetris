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

namespace Tetris::core{
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
         * the same probability for each piece (uniform distribution).
         * @return a random Tetromino piece as a unique_ptr handle.
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

        /**
         * @brief m_bag is the container used with the BagPieceRandomizer.
         */
        static std::vector<std::unique_ptr<Tetris::core::Tetromino>> m_bag;

        /**
         * @brief m_randomDevice is the device used for random generators.
         */
        static std::random_device m_randomDevice;

        /**
         * @brief m_randomGenerator is the random generator used with various distributions.
         */
        static std::mt19937 m_randomGenerator;

        /**
         * @brief m_orientationDist is the orientation for the rotation of the produced piece.
         */
        static std::uniform_int_distribution<std::mt19937::result_type> m_orientationDist;
    };
}
