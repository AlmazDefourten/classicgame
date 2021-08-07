#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->fightButton->hide();
    ui->runButton->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

Player *p1;

void MainWindow::on_startButton_clicked()
{
    ui->damageLabel->clear();
    ui->plDamageLabel->clear();
    p1 = new Player("Anton");
    setInfo();
    connect(p1, SIGNAL(s_showFightInterface()), this, SLOT(showFightInterface()));
    connect(p1, SIGNAL(s_giveEnemyInfo()), this, SLOT(getEnemyInfo()));
    connect(p1, SIGNAL(s_giveDamageInfo()), this, SLOT(getDamageInfo()));
    p1->startGame();
    ui->startButton->hide();
}

void MainWindow::restart() {
   ui->startButton->show();

}

void MainWindow::showFightInterface() {
    ui->fightButton->show();
    ui->runButton->show();
}

void MainWindow::hideFightInterface() {
    ui->fightButton->hide();
    ui->runButton->hide();
    clearInfo();
}
void MainWindow::getEnemyInfo() {
    QString info = QString::number(p1->enemy.getHealth());
    ui->enemyLabel->setText(info);
}
void MainWindow::won() {

}

void MainWindow::clearInfo() {
    ui->damageLabel->clear();
    ui->eDamageLabel->clear();
    ui->eHpLabel->clear();
    ui->eNameLabel->clear();
    ui->enemyLabel->clear();
    ui->hpLabel->clear();
    ui->levelLabel->clear();
    ui->nameLabel->clear();
    ui->plDamageLabel->clear();
}

void MainWindow::playerDead() {
    hideFightInterface();
    ui->damageLabel->setText(QString::fromStdString(p1->enemy.getName()) + " killed you!");
    ui->plDamageLabel->setText("You haved " + QString::number(p1->getGold()) + " gold " + "and " + QString::number(p1->getLevel()) + " level");
    restart();
}

void MainWindow::lose() {

}

void MainWindow::getDamageInfo() {
    QString text = QString::fromStdString(p1->enemy.getName()) + " attacked you on " + QString::number(p1->enemy.getDamage());
    ui->damageLabel->setText(text);
}
void MainWindow::on_runButton_clicked()
{
    bool i = p1->playerRun();
    if (i == 1) {
        ui->damageLabel->setText("You succesfully ran!");
        ui->plDamageLabel->clear();
        p1->enemy = Monster::getRandomMonster();
        setInfo();
    }
    else {
        ui->damageLabel->setText("Monster cathed you up!");
        p1->reduceHealth(p1->enemy.getDamage());
        ui->plDamageLabel->setText(QString::fromStdString(p1->enemy.getName()) + " attacked you on " + QString::number(p1->enemy.getDamage()));
        if (p1->isDead()) {
            playerDead();
        }
        else {
            setInfo();
        }
    }
}

void MainWindow::setInfo() {
    ui->hpLabel->setText("HP " + QString::number(p1->getHealth()));
    ui->nameLabel->setText(QString::fromStdString(p1->getName()));
    ui->levelLabel->setText("level " + QString::number(p1->getLevel()));

    ui->eDamageLabel->setText("Damage " + QString::number(p1->enemy.getDamage()));
    ui->eHpLabel->setText("HP " + QString::number(p1->enemy.getHealth()));
    ui->eNameLabel->setText(QString::fromStdString(p1->enemy.getName()));
}

void MainWindow::enemyDead() {
        p1->levelUp();

        p1->addGold(p1->enemy.getGold());
        p1->enemy = Monster::getRandomMonster();
        setInfo();
        if (p1->getLevel() >= 20) {
            hideFightInterface();
            clearInfo();
            ui->plDamageLabel->setText("You have " + QString::number(p1->getGold()) + " gold!");
            ui->damageLabel->setText("You winned! 20 level!");
        }
}

void MainWindow::on_fightButton_clicked()
{

    p1->enemy.reduceHealth(p1->getDamage());
    QString text = "You attacked enemy on " + QString::number(p1->getDamage());
    if (p1->enemy.isDead()) {
        ui->damageLabel->setText(text);
        enemyDead();
    }
    else {
    p1->reduceHealth(p1->enemy.getDamage());
    text = QString::fromStdString(p1->enemy.getName()) + " damaged you on " + QString::number(p1->enemy.getDamage());
    ui->plDamageLabel->setText(text);
    if (p1->isDead()) {
        playerDead();
    }
    else
        setInfo();
    }
}

