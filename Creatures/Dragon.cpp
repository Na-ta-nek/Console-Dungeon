#include "Dragon.hpp"

Dragon::Dragon() : Monster(0.1, //abilityChance
                           100, //abilityPoints
                           0, //armorPoints
                           0.5, //attackChance
                           25, //attackDamage
                           999, //healthPoints
                           100, //maxArmorPoints
                           999, //maxHealthPoints
                           "Dragon") {};
                           
void Dragon::ability(const std::shared_ptr<Player>& player,
                     const std::vector<std::shared_ptr<Monster>>& monsters)
{
    attack(player, getAbilityPoints());
}