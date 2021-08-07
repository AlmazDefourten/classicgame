#include "monster.h"

int Monster::getRandomNumber(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Равномерно распределяем генерацию значения из диапазона
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}


Monster::MonsterData Monster::monsterData[MAX_TYPES] {
    { "dragon", 'D', 20, 4, 100 },
    { "orc", 'o', 4, 2, 25 },
    { "slime", 's', 1, 1, 10 }
};

Monster::Monster(Type type) : Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].hp,
                              monsterData[type].damage, monsterData[type].gold) {}
Monster::Type Monster::getRandomMonster() {
    int randomNumber = getRandomNumber(0, static_cast<int>(MAX_TYPES) - 1);
    return static_cast<Type>(randomNumber);
}
