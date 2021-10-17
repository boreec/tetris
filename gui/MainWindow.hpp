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

            /**
             * @brief m_lines is the number of completed lines.
             */
            unsigned m_lines;

            /**
             * @brief m_level is the current game level.
             */
            unsigned m_level;

            /**
             * @brief m_score is the total score.
             */
            unsigned m_score;

            /**
             * @brief m_windowHeight
             */
            const int m_windowHeight = 600;

            /**
             * @brief m_windowWidth
             */
            const int m_windowWidth = 800;

            /**
             * @brief m_timeUpdate is the time in ms between two render update.
             */
            const int m_timeUpdate = 500;

            /**
             * @brief m_timeDecreaseRate is the update's time decrease rate.
             */
            const double m_timeDecreaseRate = 0.20;

        protected:
            void keyReleaseEvent(QKeyEvent* e) override;
        };
    }
}

