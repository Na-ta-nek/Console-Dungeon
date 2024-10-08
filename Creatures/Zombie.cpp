#include "Zombie.hpp"

Zombie::Zombie() : Monster(0.0, //abilityChance
                           0, //abilityPoints
                           0, //armorPoints
                           0.5, //attackChance
                           10, //attackDamage
                           100, //healthPoints
                           100, //maxArmorPoints
                           100, //maxHealthPoints
                           "Zombie") {};

void Zombie::ability(const std::shared_ptr<Player>& player,
                     const std::vector<std::shared_ptr<Monster>>& monsters) {};