#include "Monster.hpp"

Monster::Monster(double abilityChance,
                 int abilityPoints,
                 int armorPoints,
                 double attackChance,
                 int attackDamage,
                 int healthPoints,
                 int maxArmorPoints,
                 int maxHealthPoints,
                 std::string name) : Creature(armorPoints,
                                              attackDamage,
                                              healthPoints,
                                              maxArmorPoints,
                                              maxHealthPoints,
                                              name),
                                     abilityChance_(abilityChance),
                                     abilityPoints_(abilityPoints),
                                     attackChance_(attackChance) {};

double Monster::getAbilityChance() const { return abilityChance_; };
int Monster::getAbilityPoints() const { return abilityPoints_; };
double Monster::getAttackChance() const { return attackChance_; };

void Monster::monsterTurn(const std::shared_ptr<Player>& player,
                          const std::vector<std::shared_ptr<Monster>>& monsters)
{
    if(((double) rand() / (RAND_MAX)) < getAttackChance())
    {
        attack(player, getAttackDamage());
    }
    else
    {
        if(((double) rand() / (RAND_MAX)) < getAbilityChance())
        {
            ability(player, monsters);
        }
        else
        {
            defend();
        }
    }
}