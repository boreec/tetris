#ifndef PREVIEWWIDGET_HPP
#define PREVIEWWIDGET_HPP

#include <QOpenGLWidget>
#include <QPainter>
#include <QPainterPath>

#include "core/Board.hpp"
#include "core/Tetromino.hpp"
#include "gui/RendererFacilities.hpp"

namespace Tetris::gui{
    /**
     * @brief RendererPreview is a custom OpenGL widget to display next piece.
     */
    class RendererPreview : public QOpenGLWidget{
    public:

        /**
         * @brief RendererPreview's constructor
         * @param tetromino is the Tetromino piece to display.
         */
        RendererPreview(Tetris::core::Tetromino* tetromino = nullptr);

        /**
         * @brief initializeGL is called once before PaintGL or resizeGL.
         * It sets up any required OpenGL resources and state.
         */
        void initializeGL() override;

        /**
         * @brief paintGL renders the OpenGL scene.
         * It is called whenever the widget needs to be updated.
         */
        void paintGL() override;

        /**
         * @brief resizeGL is called whenever the widget has been resized.
         * @param w is the window's width.
         * @param h is the window's height.
         */
        void resizeGL(int w, int h) override;

        /**
         * @brief setTetromino defines the piece to display.
         * @param tetromino is a pointer to the next piece.
         */
        void setTetromino(Tetris::core::Tetromino* tetromino);

    private:

        /**
         * @brief m_tetromino is a handle to the Tetromino's piece to display.
         */
        Tetris::core::Tetromino* m_tetromino;
    };
}
#endif // PREVIEWWIDGET_HPP
