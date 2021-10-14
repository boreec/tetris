#ifndef PREVIEWWIDGET_HPP
#define PREVIEWWIDGET_HPP

#include <QOpenGLWidget>
#include <QPainter>
#include <QPainterPath>

#include "core/Board.hpp"
#include "core/Tetromino.hpp"
#include "gui/RendererFacilities.hpp"

namespace Tetris{
    namespace gui{
        class RendererPreview : public QOpenGLWidget{
        public:
            RendererPreview(Tetris::core::Tetromino* tetromino = nullptr);

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

            void setTetromino(Tetris::core::Tetromino* tetromino);

            void drawBlock(QPainter&, const int, const int, const int, const QColor&);

        private:
            Tetris::core::Tetromino* m_tetromino;
        };
    }
}
#endif // PREVIEWWIDGET_HPP
