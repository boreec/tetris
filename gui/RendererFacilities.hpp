#pragma once

#include <QColor>
#include <QPainter>
#include <QPainterPath>

namespace Tetris{
    namespace gui{
        class RendererFacilities{
        public:
            RendererFacilities();

            static void drawBlock(QPainter&, const int, const int, const int, const QColor&);
        };
    }
}

