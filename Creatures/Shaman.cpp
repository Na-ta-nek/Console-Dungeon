#include "Shaman.hpp"

Shaman::Shaman() : Monster(0.7, //abilityChance
                           50, //abilityPoints
                           0, //armorPoints
                           0.0, //attackChance
                           0, //attackDamage
                           100, //healthPoints
                           100, //maxArmorPoints
                           200, //maxHealthPoints
                           "Shaman") {};

Shaman::~Shaman() = default;

void Shaman::ability(const std::shared_ptr<Player>& player,
                     const std::vector<std::shared_ptr<Monster>>& monsters)
{
    monsters[rand()%monsters.size()]->increaseHealthPoints(getAbilityPoints());
}