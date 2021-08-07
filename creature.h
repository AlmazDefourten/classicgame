#ifndef CREATURE_H
#define CREATURE_H
#include <string>
using namespace std;
class Creature {
protected:
    char m_symbol;
    string m_name;
    int m_hp, m_gold, m_damage;
public:
    Creature(string name, char symbol, int hp, int damage, int gold) :
        m_symbol{symbol}, m_name{name}, m_hp{hp}, m_gold{gold}, m_damage{damage} {}
    void reduceHealth(int damage) {m_hp = (m_hp - damage > 0) ? m_hp - damage : 0;}
    bool isDead() {return m_hp <= 0;}
    void addGold(int gold) {m_gold += gold;}
    //getters:
    string getName() {return m_name;}
    char getSymbol() {return m_symbol;}
    int getHealth() {return m_hp;}
    int getGold() {return m_gold;}
    int getDamage() {return m_damage;}
};
#endif // CREATURE_H
