#include "MainWindow.hpp"
#include <QScreen>
Tetris::gui::MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initWindow();
    initWidgets();
    connectWidgets();
}

Tetris::gui::MainWindow::~MainWindow()
{

}

void Tetris::gui::MainWindow::initWindow(){
    setFixedSize(m_windowWidth, m_windowHeight);
    setWindowTitle(QString("Tetris"));
    move(screen()->geometry().center() - frameGeometry().center());
}

void Tetris::gui::MainWindow::initWidgets(){
    QFont labelFont("Courier", 12, QFont::Bold);
    m_buttonStart.setText(QString("start"));
    m_buttonPause.setText(QString("pause"));
    m_buttonAbout.setText(QString("about"));

    m_labelRandomizer.setText(QString("Randomizer"));
    m_labelRandomizer.setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    m_labelNext.setText(QString("Next"));
    m_labelNext.setFont(labelFont);
    m_labelNext.setAlignment(Qt::AlignCenter | Qt::AlignBottom);

    m_labelLines.setText(QString("Lines\n0"));
    m_labelLines.setFont(labelFont);
    m_labelLines.setAlignment(Qt::AlignCenter);


    m_labelLevel.setText(QString("Level\n0"));
    m_labelLevel.setFont(labelFont);
    m_labelLevel.setAlignment(Qt::AlignCenter);

    m_labelScore.setText(QString("Score\n0"));
    m_labelScore.setFont(labelFont);
    m_labelScore.setAlignment(Qt::AlignCenter);

    m_labelLanguage.setText(QString("Language"));
    m_labelLanguage.setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    m_comboLanguage.setFixedWidth(m_comboBoxWidth);
    m_comboLanguage.addItem("english");
    m_comboLanguage.addItem("français");
    m_comboRandomizer.setFocusPolicy(Qt::FocusPolicy::NoFocus);


    m_layoutLanguage.addWidget(&m_labelLanguage);
    m_layoutLanguage.addWidget(&m_comboLanguage);

    m_pieceRandomizer = Tetris::core::TetrominoFactory::UniformPieceRandomizer;
    m_comboRandomizer.addItem("uniform randomizer");
    m_comboRandomizer.addItem("7-bag randomizer");
    m_comboRandomizer.setFocusPolicy(Qt::FocusPolicy::NoFocus);
    m_comboRandomizer.setFixedWidth(m_comboBoxWidth);

    m_layoutRandomizer.addWidget(&m_labelRandomizer);
    m_layoutRandomizer.addWidget(&m_comboRandomizer);

    m_messageBox.setText(QString("This application is written in C++14 with Qt6 and OpenGL libraries.\n"
                                 "Have a look at the <a href=\"https://gitlab.com/boreec/tetris/\">source code</a>.\n"
                                 " You can also have a look at my personal <a href=\"https://boreec.fr/projects/\">website</a>"
                                 " where I have more projects."));
    m_messageBox.setTextFormat(Qt::RichText);
    m_messageBox.setTextInteractionFlags(Qt::TextBrowserInteraction);

    m_messageBox.setIcon(QMessageBox::Information);

    m_layoutButtons.addWidget(&m_buttonStart);
    m_layoutButtons.addWidget(&m_buttonPause);
    m_layoutButtons.addWidget(&m_buttonAbout);

    m_layoutInformations.addLayout(&m_layoutLanguage);
    m_layoutInformations.addLayout(&m_layoutRandomizer);
    m_layoutInformations.addWidget(&m_labelNext);
    m_layoutInformations.addWidget(&m_renderPreview);
    m_layoutInformations.addWidget(&m_labelLines);
    m_layoutInformations.addWidget(&m_labelLevel);
    m_layoutInformations.addWidget(&m_labelScore);
    m_layoutInformations.addLayout(&m_layoutButtons);

    QSizePolicy spLeft(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spLeft.setHorizontalStretch(2);
    m_renderGame.setSizePolicy(spLeft);
    m_layoutMain.addWidget(&m_renderGame);
    m_layoutMain.addLayout(&m_layoutInformations);

    m_mainWidget = std::make_unique<QWidget>();
    m_mainWidget->setLayout(&m_layoutMain);
    setFocusPolicy(Qt::TabFocus);

    m_timer = std::unique_ptr<QTimer>(new QTimer(this));
    this->setCentralWidget(m_mainWidget.get());
}

void Tetris::gui::MainWindow::connectWidgets(){
    QObject::connect(&m_comboRandomizer, SIGNAL(currentTextChanged(QString)), this, SLOT(changePiecePandomizer()));
    QObject::connect(&m_buttonStart, SIGNAL(clicked()), this, SLOT(initGameArea()));
    QObject::connect(&m_buttonPause, SIGNAL(clicked()), this, SLOT(pauseGame()));
    QObject::connect(&m_buttonAbout, SIGNAL(clicked()), &m_messageBox, SLOT(exec()));
    QObject::connect(m_timer.get(), SIGNAL(timeout()), this, SLOT(updateGameArea()));
}

void Tetris::gui::MainWindow::initGameArea(){
   if(m_buttonStart.text() == "resume"){
       m_timer->start();
       m_buttonStart.setText("restart");
   }else{
       m_board.clear();
       m_board.setCurrentPiece(m_pieceRandomizer());
       m_board.setNextPiece(m_pieceRandomizer());
       m_renderGame.setBoard(&m_board);
       m_renderGame.setGameOver(false);

       m_renderPreview.setTetromino(m_board.getNextPiece());
       m_renderPreview.update();
       m_buttonStart.setText(QString("restart"));

       m_lines = 0;
       m_level = 0;
       m_score = 0;

       m_labelLines.setText(QString("Lines\n0"));
       m_labelLevel.setText(QString("Level\n0"));
       m_labelScore.setText(QString("Score\n0"));

       m_timer->stop();
       m_timer->start(500);
   }
}

void Tetris::gui::MainWindow::updateGameArea(){
    if(!m_board.canMoveCurrentPieceDown()){
        m_board.dropCurrentPiece();
        m_board.swapPieces(m_pieceRandomizer());
        m_renderPreview.setTetromino(m_board.getNextPiece());
        if(int l = m_board.removeCompletedLines()){
            m_lines += l;
            addScore(l);
            m_labelLines.setText(QString("Lines\n") + QString::number(m_lines));
            m_labelScore.setText(QString("Score\n") + QString::number(m_score));

            if(m_lines / 10 > (m_lines - l) / 10){
              m_level++;
              m_labelLevel.setText(QString("Level\n") + QString::number(m_level));
              m_timer->stop();
              m_timer->start(m_timeUpdate * std::pow(1 - m_timeDecreaseRate, m_level));
            }
        }else if(m_board.isGameOver()){
            m_renderGame.setGameOver(true);
            m_renderGame.update();
            m_timer->stop();
        }
        m_renderPreview.update();
    }else{
        m_board.getCurrentPiece()->setY(m_board.getCurrentPiece()->getY() + 1);
    }
    m_renderGame.update();
}

void Tetris::gui::MainWindow::addScore(const int completedLines){
    switch(completedLines) {
        case 1:
            m_score += 40 * (m_level  + 1);
            break;
        case 2:
            m_score += 100 * (m_level + 1);
            break;
        case 3:
            m_score += 300 * (m_level + 1);
            break;
        case 4:
            m_score += 1200 * (m_level + 1);
            break;
        default:
            throw std::runtime_error("Can't complete more than 4 lines at once.");
    }
}

void Tetris::gui::MainWindow::keyReleaseEvent(QKeyEvent* e){
    // Change piece coordinates after checking if it can moves in
    // the pressed direction and rendering the move.
    if(e->key() == Qt::Key_Left){
        if(m_board.canMoveCurrentPieceLeft()){
            m_renderGame.update();
            m_board.getCurrentPiece()->setX(m_board.getCurrentPiece()->getX() - 1);
        }
    }else if(e->key() == Qt::Key_Right){
        if(m_board.canMoveCurrentPieceRight()){
            m_renderGame.update();
            m_board.getCurrentPiece()->setX(m_board.getCurrentPiece()->getX() + 1);
        }
    }else if(e->key() == Qt::Key_Up){
        if(m_board.canRotateCurrentPiece()){
            m_renderGame.update();
            m_board.getCurrentPiece()->setOrientation((m_board.getCurrentPiece()->getOrientation() + 1) % 4);
        }
    }else if(e->key() == Qt::Key_Down){
        if(m_board.canMoveCurrentPieceDown()){
            m_renderGame.update();
            m_board.getCurrentPiece()->setY(m_board.getCurrentPiece()->getY() + 1);
        }
    }
}

void Tetris::gui::MainWindow::pauseGame(){
    m_timer->stop();
    m_buttonStart.setText("resume");
}
void Tetris::gui::MainWindow::changePiecePandomizer(){
    if(m_comboRandomizer.currentText().contains("uniform")){
        m_pieceRandomizer = Tetris::core::TetrominoFactory::UniformPieceRandomizer;
    }
    else if(m_comboRandomizer.currentText().contains("7-bag")){
        m_pieceRandomizer = Tetris::core::TetrominoFactory::BagPieceRandomizer;
    }else{
        throw std::runtime_error("Unknown piece randomizer");
    }
}
