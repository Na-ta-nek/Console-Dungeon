#include "Skeleton.hpp"

Skeleton::Skeleton() : Monster(0.0, //abilityChance
                               0, //abilityPoints
                               0, //armorPoints
                               0.85, //attackChance
                               5, //attackDamage
                               50, //healthPoints
                               100, //maxArmorPoints
                               50, //maxHealthPoints
                               "Skeleton") {};

void Skeleton::ability(const std::shared_ptr<Player>& player,
                       const std::vector<std::shared_ptr<Monster>>& monsters) {};