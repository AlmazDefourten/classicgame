#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "player.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void restart();
    void won();
    void lose();
    void enemyDead();
    void clearInfo();
    void playerDead();
    void hideFightInterface();
    void setInfo();
public slots:
    void showFightInterface();
    void getEnemyInfo();
    void getDamageInfo();
private slots:
    void on_startButton_clicked();

    void on_runButton_clicked();

    void on_fightButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
