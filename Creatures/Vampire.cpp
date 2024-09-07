#include "Vampire.hpp"

Vampire::Vampire() : Monster(0.3, //abilityChance
                             15, //abilityPoints
                             0, //armorPoints
                             0.0, //attackChance
                             15, //attackDamage
                             75, //healthPoints
                             100, //maxArmorPoints
                             200, //maxHealthPoints
                             "Vampire") {};

Vampire::~Vampire() = default;

void Vampire::ability(const std::shared_ptr<Player>& player,
                     const std::vector<std::shared_ptr<Monster>>& monsters)
{
    attack(player, getAttackDamage());
    increaseHealthPoints(getAbilityPoints());
}