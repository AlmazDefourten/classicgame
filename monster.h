#ifndef MONSTER_H
#define MONSTER_H
#include "creature.h"



class Monster : public Creature
{
public:
    static int getRandomNumber(int min, int max);
    enum Type {
        DRAGON,
        ORC,
        SLIME,
        MAX_TYPES
    };
    struct MonsterData {
        string name;
        char symbol;
        int hp;
        int damage;
        int gold;
    };
    static MonsterData monsterData[MAX_TYPES];
    Monster(Type type);
    static Type getRandomMonster();
};

#endif // MONSTER_H
