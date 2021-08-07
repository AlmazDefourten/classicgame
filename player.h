#ifndef PLAYER_H
#define PLAYER_H
#include "creature.h"
#include <iostream>
#include "monster.h"
#include "mainwindow.h"
#include "QThread"


class Player : public QThread, public Creature
{
    Q_OBJECT
protected:
    int m_level = 1;

public:
    Monster enemy = Monster::getRandomMonster();
    Player(const string &name, char symbol = '@', int hp = 20, int damage = 1, int gold = 0);
    void levelUp();
    int getLevel() {return m_level;}
    bool hasWon() {return m_level >= 20;}
    void heal();
    bool playerRun();
public slots:
    void startGame();
    void fight();
signals:
    void s_showFightInterface();
    void s_giveEnemyInfo();
    void s_giveDamageInfo();
};

#endif // PLAYER_H
