#include "gui/MainWindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Tetris::gui::MainWindow w;
    w.show();
    return a.exec();
}
