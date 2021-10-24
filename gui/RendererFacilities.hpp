#pragma once

#include <QColor>
#include <QPainter>
#include <QPainterPath>

namespace Tetris::gui{
        /**
         * @brief RendererFacilities provides facilities for drawing.
         */
        class RendererFacilities{
        public:

            /**
             * @brief RendererFacilities's constructor is inexistant
             * because this is a static class only.
             */
            RendererFacilities() = delete;

            /**
             * @brief drawBlock draws a colourfull block according to the provided parameters.
             * @param painter is the surface to draw on.
             * @param x is the first coordinate on the x axis.
             * @param y is the first coordinate on the y axis.
             * @param size is the size used for the height and width of the block.
             * @param colour is the colour of the block.
             */
            static void drawBlock(QPainter& painter, const int x, const int y, const int size, const QColor& colour);
        };
}

