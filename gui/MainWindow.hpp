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

namespace Tetris::gui{

    /**
     * \mainpage
     * \section intro_sec Introduction
     * The MainWindow class represents the window running the application.
     * It computes the game states according to a QTimer object.
     *
     * RendererGame is the class dealing with the game drawing.
     */
    class MainWindow : public QMainWindow{
        Q_OBJECT

    public:

        /**
         * @brief MainWindow's constructor
         * @param parent is by default nullptr because there's no parent.
         */
        MainWindow(QWidget *parent = nullptr);

        /**
         * Deallocate dynamic memory created by MainWindow.
         * */
        ~MainWindow();

    public slots:

        /**
         * @brief initGameArea initialize game drawing area.
         */
        void initGameArea();

        /**
         * @brief updateGameArea update game area depending on the game state.
         */
        void updateGameArea();

        /**
         * @brief pauseGame pause the timer that update the game drawing area.
         */
        void pauseGame();

        /**
         * @brief changePiecePandomizer dynamically change the piece generator.
         */
        void changePiecePandomizer();

    private:

        /*
         * Initialize window' properties (size, position...).
         * */
        void initWindow();

        /*
         * Initialize window' widget' properties.
         * */
        void initWidgets();

        void addScore(const int);

        /**
         * @brief connectWidgets gathers every connection for widgets and their signals.
         */
        void connectWidgets();

        void blinkLines(const int lineStart, const int lineStop);

        QPushButton* m_buttonStart;
        QPushButton* m_buttonPause;
        QPushButton* m_buttonAbout;
        QComboBox* m_comboRandomizer;
        QLabel* m_labelRandomizer;
        QLabel* m_labelNext;
        QLabel* m_labelLines;
        QLabel* m_labelLevel;
        QLabel* m_labelScore;
        QMessageBox* m_messageBox;
        Tetris::gui::RendererGame* m_renderGame;
        Tetris::gui::RendererPreview* m_renderPreview;

        QHBoxLayout* m_layoutMain;
        QHBoxLayout* m_layoutRandomizer;
        QVBoxLayout* m_layoutInformations;
        QHBoxLayout* m_layoutButtons;

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

        /**
         * @brief m_comboBoxWidth is the width used for comboxBox widgets.
         */
        const int m_comboBoxWidth = 150;

    protected:
        void keyReleaseEvent(QKeyEvent* e) override;
    };
}

