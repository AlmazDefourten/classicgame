#include "player.h"
#include "monster.h"

Player::Player(const string &name, char symbol, int hp, int damage, int gold) : Creature(name, symbol, hp, damage, gold)
{}

void Player::levelUp() {
    heal();
    ++m_level;
    ++m_damage;
}

void Player::startGame() {
    emit s_showFightInterface();
    emit s_giveEnemyInfo();
}

void Player::heal() {
    m_hp = 20;
}

void Player::fight() {
    for (int i = 0; i < 100; ++i) {
        std::cout << i << std::endl;
        sleep(1);
    }
}

bool Player::playerRun() {
    int random = Monster::getRandomNumber(0, 1);
    if (random == 1)
        return 1;

    else {
        return 0;
    }
}
