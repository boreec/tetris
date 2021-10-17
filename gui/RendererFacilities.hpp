#pragma once

#include <QColor>
#include <QPainter>
#include <QPainterPath>

namespace Tetris{
    namespace gui{
        /**
         * @brief RendererFacilities provides facilities for drawing.
         */
        class RendererFacilities{
        public:
            RendererFacilities()=delete;

            static void drawBlock(QPainter&, const int, const int, const int, const QColor&);
        };
    }
}

