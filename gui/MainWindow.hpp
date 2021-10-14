#pragma once

#include <algorithm>
#include <iostream>
#include <random>

#include <QKeyEvent>
#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QScreen>
#include <QSizePolicy>
#include <QTimer>

#include "core/Tetromino.hpp"
#include "core/TetrominoFactory.hpp"
#include "gui/RendererGame.hpp"
#include "gui/RendererPreview.hpp"

namespace Tetris{
    namespace gui{
        class MainWindow : public QMainWindow{
            Q_OBJECT

        public:
            MainWindow(QWidget *parent = nullptr);
            ~MainWindow();

        public slots:
            void init_game_area();
            void update_game_area();

        private:
            /*
             * Initialize window' properties (size, position...).
             * */
            void init_window();

            /*
             * Initialize window' widget' properties.
             * */
            void init_widgets();

            void addScore(const int);

            QPushButton m_buttonStart;
            QPushButton m_buttonPause;
            QPushButton m_buttonAbout;
            QLabel m_labelNext;
            QLabel m_labelLines;
            QLabel m_labelLevel;
            QLabel m_labelScore;

            Tetris::gui::RendererGame m_renderGame;
            Tetris::gui::RendererPreview m_renderPreview;

            QHBoxLayout m_layoutMain;
            QVBoxLayout m_layoutInformations;
            QHBoxLayout m_layoutButtons;

            Tetris::core::Board* m_board;

            QTimer* m_timer;

            unsigned m_lines;
            unsigned m_level;
            unsigned m_score;
        protected:
            void keyReleaseEvent(QKeyEvent* e) override;
        };
    }
}

