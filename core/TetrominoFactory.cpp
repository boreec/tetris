#include "TetrominoFactory.hpp"

TetrominoFactory::TetrominoFactory()
{

}

Tetromino* TetrominoFactory::generateRandomTetromino(){
    Tetromino* t = nullptr;

    // Choose a random Tetromino piece
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist4(0, 7);

    switch(dist4(rng)){
        case 0:
            t = new Tetromino_T();
            break;
        case 1:
            t = new Tetromino_O();
            break;
        case 2:
            t = new Tetromino_I();
            break;
        case 3:
            t = new Tetromino_L();
            break;
        case 4:
            t = new Tetromino_J();
            break;
        case 5:
            t = new Tetromino_S();
            break;
        case 6:
            t = new Tetromino_T();
            break;
        default:
            t = new Tetromino_Z();
            break;
    }
    t->setOrientation(dist4(rng));
    return t;
}
