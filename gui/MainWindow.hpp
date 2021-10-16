#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <random>

#include <QComboBox>
#include <QKeyEvent>
#include <QMainWindow>
#include <QMessageBox>
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
        /**
         * @brief MainWindow is the widget representing the main window.
         */
        class MainWindow : public QMainWindow{
            Q_OBJECT

        public:
            MainWindow(QWidget *parent = nullptr);
            ~MainWindow();

        public slots:
            void init_game_area();
            void update_game_area();
            void pause_game();
            void change_piece_randomizer();

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
            QComboBox m_comboRandomizer;
            QLabel m_labelRandomizer;
            QLabel m_labelNext;
            QLabel m_labelLines;
            QLabel m_labelLevel;
            QLabel m_labelScore;
            QMessageBox m_messageBox;
            Tetris::gui::RendererGame m_renderGame;
            Tetris::gui::RendererPreview m_renderPreview;

            QHBoxLayout m_layoutMain;
            QVBoxLayout m_layoutInformations;
            QHBoxLayout m_layoutButtons;

            Tetris::core::Board m_board;

            std::unique_ptr<QTimer> m_timer;

            std::function<std::unique_ptr<Tetris::core::Tetromino>()> m_pieceRandomizer;
            unsigned m_lines;
            unsigned m_level;
            unsigned m_score;

            const int window_height = 600;

            const int window_width = 800;
            // time between two updates in ms.
            const int time_update = 500;

            // 20% speed increasement on a new level.
            const double time_decrease_rate = 0.20;
        protected:
            void keyReleaseEvent(QKeyEvent* e) override;
        };
    }
}

