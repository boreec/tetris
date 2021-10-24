#pragma once

#include <QOpenGLWidget>
#include <QPainter>
#include <QPainterPath>
#include <QColor>

#include "core/Board.hpp"
#include "gui/RendererFacilities.hpp"

namespace Tetris::gui{
    /**
     * @brief RendererGame is a custom OpenGL widget to display the game.
     */
    class RendererGame : public QOpenGLWidget{
    public:
        RendererGame();

        /*
         * Called once before paintGL() or resizeGL().
         * Set up any required OpenGL resources and state.
         * */
        void initializeGL() override;

        /*
         * Renders the OpenGL scene. Gets called whenever
         * the widget needs to be updated.
         * */
        void paintGL() override;

        /*
         * Called whenever the widget has been resized.
         * */
        void resizeGL(int w, int h) override;

        void setBoard(Tetris::core::Board* board);

        void setGameOver(const bool);

        void drawGameOverScreen();


    private:
        Tetris::core::Board* m_board;
        bool m_gameOver;
    };
}
