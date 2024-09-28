#include "Orc.hpp"

Orc::Orc() : Monster(0.0, //abilityChance
                     0, //abilityPoints
                     100, //armorPoints
                     0.7, //attackChance
                     15, //attackDamage
                     250, //healthPoints
                     100, //maxArmorPoints
                     250, //maxHealthPoints
                     "Orc") {};

void Orc::ability(const std::shared_ptr<Player>& player,
                  const std::vector<std::shared_ptr<Monster>>& monsters) {};