#include "DeathKnight.hpp"

DeathKnight::DeathKnight() : Monster(0.3, //abilityChance
                           25, //abilityPoints
                           100, //armorPoints
                           0.6, //attackChance
                           15, //attackDamage
                           100, //healthPoints
                           250, //maxArmorPoints
                           100, //maxHealthPoints
                           "DeathKnight") {};

DeathKnight::~DeathKnight() = default;

void DeathKnight::ability(const std::shared_ptr<Player>& player,
                     const std::vector<std::shared_ptr<Monster>>& monsters)
{
    for(auto monster : monsters)
    {
        increaseArmorPoints(getAbilityPoints());
    }
}