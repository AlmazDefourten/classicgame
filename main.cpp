#include "mainwindow.h"
#include <cstdlib> // для rand() и srand()
#include <ctime> // для time()
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
