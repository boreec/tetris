#include "TetrominoFactory.hpp"

std::vector<std::unique_ptr<Tetris::core::Tetromino>> Tetris::core::TetrominoFactory::m_bag;

std::random_device Tetris::core::TetrominoFactory::m_randomDevice;

std::mt19937 Tetris::core::TetrominoFactory::m_randomGenerator(m_randomDevice());

std::uniform_int_distribution<std::mt19937::result_type> Tetris::core::TetrominoFactory::m_orientationDist(0, 4);

std::unique_ptr<Tetris::core::Tetromino> Tetris::core::TetrominoFactory::UniformPieceRandomizer(){
    std::unique_ptr<Tetris::core::Tetromino> ptr;

    std::uniform_int_distribution<std::mt19937::result_type> distTetromino(0, 7);

    switch(distTetromino(m_randomGenerator)){
        case 0:
            ptr = std::unique_ptr<Tetris::core::Tetromino>(new Tetromino_T());
            break;
        case 1:
            ptr = std::unique_ptr<Tetris::core::Tetromino>(new Tetromino_O());
            break;
        case 2:
            ptr = std::unique_ptr<Tetris::core::Tetromino>(new Tetromino_I());
            break;
        case 3:
            ptr = std::unique_ptr<Tetris::core::Tetromino>(new Tetromino_L());
            break;
        case 4:
            ptr = std::unique_ptr<Tetris::core::Tetromino>(new Tetromino_J());
            break;
        case 5:
            ptr = std::unique_ptr<Tetris::core::Tetromino>(new Tetromino_S());
            break;
        case 6:
            ptr = std::unique_ptr<Tetris::core::Tetromino>(new Tetromino_Z());
            break;
        default:
            ptr = std::unique_ptr<Tetris::core::Tetromino>(new Tetromino_T());
            break;
    }
    ptr->setOrientation(m_orientationDist(m_randomGenerator));
    return ptr;
}

std::unique_ptr<Tetris::core::Tetromino> Tetris::core::TetrominoFactory::BagPieceRandomizer(){
    std::unique_ptr<Tetris::core::Tetromino> ptr;

    if(m_bag.empty()){
       m_bag.push_back(std::unique_ptr<Tetris::core::Tetromino>(new Tetromino_I()));
       m_bag.push_back(std::unique_ptr<Tetris::core::Tetromino>(new Tetromino_J()));
       m_bag.push_back(std::unique_ptr<Tetris::core::Tetromino>(new Tetromino_L()));
       m_bag.push_back(std::unique_ptr<Tetris::core::Tetromino>(new Tetromino_O()));
       m_bag.push_back(std::unique_ptr<Tetris::core::Tetromino>(new Tetromino_S()));
       m_bag.push_back(std::unique_ptr<Tetris::core::Tetromino>(new Tetromino_T()));
       m_bag.push_back(std::unique_ptr<Tetris::core::Tetromino>(new Tetromino_Z()));
    }

    if(m_bag.size() > 1)
        std::shuffle(m_bag.begin(), m_bag.end(), m_randomGenerator);
    ptr = std::move(m_bag.back());
    m_bag.pop_back();
    ptr->setOrientation(m_orientationDist(m_randomGenerator));
    return ptr;
}
