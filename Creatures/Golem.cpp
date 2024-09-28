#include "Golem.hpp"

Golem::Golem() : Monster(0.1, //abilityChance
                         30, //abilityPoints
                         200, //armorPoints
                         0.3, //attackChance
                         50, //attackDamage
                         500, //healthPoints
                         200, //maxArmorPoints
                         500, //maxHealthPoints
                         "Golem") {};

void Golem::ability(const std::shared_ptr<Player>& player,
                    const std::vector<std::shared_ptr<Monster>>& monsters)
{
    defend();
    increaseArmorPoints(getAbilityPoints());
}