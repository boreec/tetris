#include "TetrominoFactory.hpp"

Tetris::core::TetrominoFactory::TetrominoFactory()
{

}

std::unique_ptr<Tetris::core::Tetromino> Tetris::core::TetrominoFactory::generateRandomTetromino(){
    std::unique_ptr<Tetris::core::Tetromino> ptr;

    // Choose a random Tetromino piece
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distTetromino(0, 7);
    std::uniform_int_distribution<std::mt19937::result_type> dist4(0,4);

    switch(distTetromino(rng)){
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
    ptr->setOrientation(dist4(rng));
    return ptr;
}
