#pragma once
#include <iomanip>
#include <iostream>

#include "Creature.hpp"
#include "Player.hpp"

class Monster : public Creature
{
private:
    double abilityChance_ = 0.0;
    int abilityPoints_ = 0;
    double attackChance_ = 0.0;
public:
    Monster() = default;
    Monster(double abilityChance,
            int abilityPoints,
            int armorPoints,
            double attackChance,
            int attackDamage,
            int healthPoints,
            int maxArmorPoints,
            int maxHealthPoints,
            std::string name);

    virtual void ability(const std::shared_ptr<Player>& player,
                         const std::vector<std::shared_ptr<Monster>>& monsters) = 0;
    double getAbilityChance() const;
    int getAbilityPoints() const;
    double getAttackChance() const;
    void monsterTurn(const std::shared_ptr<Player>& player,
                     const std::vector<std::shared_ptr<Monster>>& monsters);
};