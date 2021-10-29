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

        /**
         * @brief RendererGame's constructor.
         */
        RendererGame();

        /**
         * @brief initializeGL is called once before paintGL() or resizeGL().
         * It sets up any requiredd OpenGL ressources and state.
         */
        void initializeGL() override;

        /**
         * @brief paintGL renders the OpenGL scene. It gets called
         * whenever the widget needs to be updated.
         */
        void paintGL() override;

        /**
         * @brief resizeGL is called whenever the widget has been resized.
         * @param w is window with.
         * @param h is window height.
         */
        void resizeGL(int w, int h) override;

        /**
         * @brief setBoard defines the board to draw.
         * @param board is the new board.
         */
        void setBoard(Tetris::core::Board* board);

        /**
         * @brief setGameOver defines the game over state.
         * @param b is the new game over state.
         */
        void setGameOver(const bool b);

        /**
         * @brief drawGameOverScreen is called when the game over state
         * is reached.
         */
        void drawGameOverScreen();

        /**
         * @brief setExtraShapes defines extra shapes to draw after everything.
         * It can be used to create animation (blinking, translation...).
         * @param extraShapes the extra shapes to draw.
         */
        void setExtraShapes(const std::vector<QPainterPath>& extraShapes);

        /**
         * @brief setExtraColor defines the color to use for the extra shapes.
         * @param c is the color for the extra shapes.
         */
        void setExtraColor(const QColor& c);

        /**
         * @brief getCellSize gives the size of a cell according to window's dimensions.
         */
        unsigned getCellSize() const;

        /**
         * @brief getMarginLeft gives the margin from the left from which the board is drawn.
         */
        unsigned getMarginLeft() const;

        /**
         * @brief getMarginTop gives the margin from the top from which the board is drawn.
         */
        unsigned getMarginTop() const;

    private:

        /**
         * @brief m_board is the board to draw.
         */
        Tetris::core::Board* m_board;

        /**
         * @brief m_gameOver is the game over state.
         */
        bool m_gameOver;

        /**
         * @brief m_extraShapes are the extra shapes to draw.
         */
        std::vector<QPainterPath> m_extraShapes;

        /**
         * @brief m_extraColor is the color used for the extra shapes.
         */
        QColor m_extraColor;

        /**
         * @brief m_cellSize is the size of the cells making the Tetris area.
         */
        unsigned m_cellSize;

        /**
         * @brief m_marginLeft is the left margin from which the board is drawn.
         */
        unsigned m_marginLeft;

        /**
         * @brief m_marginTop is the top margin from which the board is drawn.
         */
        unsigned m_marginTop;
    };
}
