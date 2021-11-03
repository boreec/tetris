#include "MainWindow.hpp"
#include <QScreen>
#include <QThread>
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
    /* Initialize private members related to game. */
    m_pieceRandomizer = Tetris::core::TetrominoFactory::UniformPieceRandomizer;
    m_timer = std::make_unique<QTimer>(this);

    /* Initialize game labels. */
    QFont labelFont("Courier", 12, QFont::Bold);
    m_labelNext = new QLabel("Next", this);
    m_labelNext->setFont(labelFont);
    m_labelLines = new QLabel("Lines\n0", this);
    m_labelLines->setFont(labelFont);
    m_labelLevel = new QLabel("Level\n0", this);
    m_labelLevel->setFont(labelFont);
    m_labelScore = new QLabel("Score\n0", this);
    m_labelScore->setText(QString("Score\n0"));
    m_labelScore->setFont((labelFont));

    /* Initialize option labels. */
    m_labelRandomizer = new QLabel("Randomizer", this);

    /* Initialize option combo boxes. */
    m_comboRandomizer = new QComboBox(this);
    m_comboRandomizer->addItem("uniform randomizer");
    m_comboRandomizer->addItem("7-bag randomizer");

    /* Initialize buttons */
    m_buttonStart = new QPushButton("start", this);
    m_buttonPause = new QPushButton("pause", this);
    m_buttonAbout = new QPushButton("about", this);

    /* Initialize message box in about button. */
    m_messageBox = new QMessageBox(this);
    m_messageBox->setText(QString("This application is written in C++14 with Qt6 and OpenGL libraries.\n"
                                 "Have a look at the <a href=\"https://gitlab.com/boreec/tetris/\">source code</a>.\n"
                                 " You can also have a look at my personal <a href=\"https://boreec.fr/projects/\">website</a>"
                                 " where I have more projects."));
    m_messageBox->setTextFormat(Qt::RichText);
    m_messageBox->setTextInteractionFlags(Qt::TextBrowserInteraction);
    m_messageBox->setIcon(QMessageBox::Information);

    /* Initialize rendering widgets. */
    m_renderGame = new Tetris::gui::RendererGame();
    m_renderPreview = new Tetris::gui::RendererPreview();

    /* Align game labels on the center. */
    m_labelNext->setAlignment(Qt::AlignCenter | Qt::AlignBottom);
    m_labelLines->setAlignment(Qt::AlignCenter);
    m_labelLevel->setAlignment(Qt::AlignCenter);
    m_labelScore->setAlignment(Qt::AlignCenter);

    /* Align option labels on the left. */
    m_labelRandomizer->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    /* Set option combo boxes width. */
    m_comboRandomizer->setFixedWidth(m_comboBoxWidth);

    /* Set option combo boxes focus policies. */
    m_comboRandomizer->setFocusPolicy(Qt::FocusPolicy::NoFocus);


    /* Horizontal layout for randomizer widgets. */
    m_layoutRandomizer = new QHBoxLayout();
    m_layoutRandomizer->addWidget(m_labelRandomizer);
    m_layoutRandomizer->addWidget(m_comboRandomizer);

    /* Horizontal layout for buttons. */
    m_layoutButtons = new QHBoxLayout();
    m_layoutButtons->addWidget(m_buttonStart);
    m_layoutButtons->addWidget(m_buttonPause);
    m_layoutButtons->addWidget(m_buttonAbout);

    /* Vertical layout gathering language, randomizer, game labels, and buttons layouts. */
    m_layoutInformations = new QVBoxLayout();
    m_layoutInformations->addLayout(m_layoutRandomizer);
    m_layoutInformations->addWidget(m_labelNext);
    m_layoutInformations->addWidget(m_renderPreview);
    m_layoutInformations->addWidget(m_labelLines);
    m_layoutInformations->addWidget(m_labelLevel);
    m_layoutInformations->addWidget(m_labelScore);
    m_layoutInformations->addLayout(m_layoutButtons);

    /* Set size of game rendering widget 2/3 of window's width. */
    QSizePolicy spLeft(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spLeft.setHorizontalStretch(2);
    m_renderGame->setSizePolicy(spLeft);

    /* Vertical layout for main layout. */
    m_layoutMain = new QHBoxLayout();
    m_layoutMain->addWidget(m_renderGame);
    m_layoutMain->addLayout(m_layoutInformations);

    // add Vertical layout to the main widget.
    QWidget* mainWidget = new QWidget(); // MainWindow will delete it
    mainWidget->setLayout(m_layoutMain);
    setFocusPolicy(Qt::TabFocus);
    this->setCentralWidget(mainWidget);
}

void Tetris::gui::MainWindow::connectWidgets(){
    QObject::connect(m_comboRandomizer, SIGNAL(currentTextChanged(QString)), this, SLOT(changePiecePandomizer()));
    QObject::connect(m_buttonStart, SIGNAL(clicked()), this, SLOT(initGameArea()));
    QObject::connect(m_buttonPause, SIGNAL(clicked()), this, SLOT(pauseGame()));
    QObject::connect(m_buttonAbout, SIGNAL(clicked()), m_messageBox, SLOT(exec()));
    QObject::connect(m_timer.get(), SIGNAL(timeout()), this, SLOT(updateGameArea()));
}

void Tetris::gui::MainWindow::initGameArea(){
   if(m_buttonStart->text() == "resume"){
       m_timer->start();
       m_buttonStart->setText("restart");
   }else{
       m_board.clear();
       m_board.setCurrentPiece(m_pieceRandomizer());
       m_board.setNextPiece(m_pieceRandomizer());
       m_renderGame->setBoard(&m_board);
       m_renderGame->setGameOver(false);

       m_renderPreview->setTetromino(m_board.getNextPiece());
       m_renderPreview->update();
       m_buttonStart->setText(QString("restart"));

       m_lines = 0;
       m_level = 0;
       m_score = 0;

       m_labelLines->setText(QString("Lines\n0"));
       m_labelLevel->setText(QString("Level\n0"));
       m_labelScore->setText(QString("Score\n0"));

       m_timer->stop();
       m_timer->start(m_timeUpdate);
   }
}

void Tetris::gui::MainWindow::updateGameArea(){
    if(!m_board.canMoveCurrentPieceDown()){
        m_board.dropCurrentPiece();
        m_board.swapPieces(m_pieceRandomizer());
        m_renderPreview->setTetromino(m_board.getNextPiece());

        if(auto completedRange = m_board.hasCompletedLines(); completedRange.first && completedRange.second){
            m_lines += completedRange.second - completedRange.first;
            addScore(completedRange.second - completedRange.first);
            m_labelLines->setText(QString("Lines\n") + QString::number(m_lines));
            m_labelScore->setText(QString("Score\n") + QString::number(m_score));
            if(m_lines / 10 > (m_lines - (completedRange.second - completedRange.first)) / 10){
              m_level++;
              m_labelLevel->setText(QString("Level\n") + QString::number(m_level));
              m_timer->stop();
              m_timer->start(m_timeUpdate * std::pow(1 - m_timeDecreaseRate, m_level));
            }

            m_timer->stop();
            blinkLines(completedRange.first, completedRange.second);
            m_timer->start();
            m_board.eraseLines(completedRange);

        }else if(m_board.isGameOver()){
            m_renderGame->setGameOver(true);
            m_renderGame->update();
            m_timer->stop();
        }
        m_renderPreview->update();
    }else{
        m_board.getCurrentPiece()->setY(m_board.getCurrentPiece()->getY() + 1);
    }
    m_renderGame->update();
}

void Tetris::gui::MainWindow::blinkLines(const int lineStart, const int lineStop){
    QPainterPath blinkArea;
    blinkArea.lineTo(m_renderGame->getMarginLeft(), m_renderGame->getMarginTop() + m_renderGame->getCellSize() * lineStart);
    blinkArea.lineTo(m_renderGame->getMarginLeft() + m_renderGame->getCellSize() * Tetris::core::Board::m_width,
                     m_renderGame->getMarginTop() + m_renderGame->getCellSize() * lineStart);
    blinkArea.lineTo(m_renderGame->getMarginLeft() + m_renderGame->getCellSize() * Tetris::core::Board::m_width,
                     m_renderGame->getMarginTop() + m_renderGame->getCellSize() * lineStop);
    blinkArea.lineTo(m_renderGame->getMarginLeft(), m_renderGame->getMarginTop() + m_renderGame->getCellSize() * lineStop);
    blinkArea.lineTo(m_renderGame->getMarginLeft(), m_renderGame->getMarginTop() + m_renderGame->getCellSize() * lineStart);

    m_renderGame->setExtraShapes({blinkArea});
    m_renderGame->setExtraColor(Qt::black); // first blink
    m_renderGame->repaint();
    QThread::msleep(50);

    m_renderGame->setExtraColor(QColor(0,0,0,0));
    m_renderGame->repaint();
    QThread::msleep(50);

    m_renderGame->setExtraColor(Qt::black); // second blink
    m_renderGame->repaint();
    QThread::msleep(50);

    m_renderGame->setExtraColor(QColor(0,0,0,0));
    m_renderGame->repaint();

    QThread::msleep(50);
    m_renderGame->setExtraColor(Qt::black); // first blink
    m_renderGame->repaint();
    m_renderGame->setExtraShapes({});
    m_renderGame->setExtraColor(QColor(0,0,0,0));
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
            m_renderGame->update();
            m_board.getCurrentPiece()->setX(m_board.getCurrentPiece()->getX() - 1);
        }
    }else if(e->key() == Qt::Key_Right){
        if(m_board.canMoveCurrentPieceRight()){
            m_renderGame->update();
            m_board.getCurrentPiece()->setX(m_board.getCurrentPiece()->getX() + 1);
        }
    }else if(e->key() == Qt::Key_Up){
        if(m_board.canRotateCurrentPiece()){
            m_renderGame->update();
            m_board.getCurrentPiece()->setOrientation((m_board.getCurrentPiece()->getOrientation() + 1) % 4);
        }
    }else if(e->key() == Qt::Key_Down){
        if(m_board.canMoveCurrentPieceDown()){
            m_renderGame->update();
            m_board.getCurrentPiece()->setY(m_board.getCurrentPiece()->getY() + 1);
        }
    }
}

void Tetris::gui::MainWindow::pauseGame(){
    m_timer->stop();
    m_buttonStart->setText("resume");
}

void Tetris::gui::MainWindow::changePiecePandomizer(){
    if(m_comboRandomizer->currentText().contains("uniform")){
        m_pieceRandomizer = Tetris::core::TetrominoFactory::UniformPieceRandomizer;
    }
    else if(m_comboRandomizer->currentText().contains("7-bag")){
        m_pieceRandomizer = Tetris::core::TetrominoFactory::BagPieceRandomizer;
    }else{
        throw std::runtime_error("Unknown piece randomizer");
    }
}
