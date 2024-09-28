#include "Wizard.hpp"

Wizard::Wizard() : Monster(0.4, //abilityChance
                           50, //abilityPoints
                           0, //armorPoints
                           0.6, //attackChance
                           5, //attackDamage
                           100, //healthPoints
                           100, //maxArmorPoints
                           100, //maxHealthPoints
                           "Wizard") {};

void Wizard::ability(const std::shared_ptr<Player>& player,
                     const std::vector<std::shared_ptr<Monster>>& monsters)
{
    attack(player, getAbilityPoints());
}