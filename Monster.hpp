#pragma once
#include <iomanip>
#include <iostream>

#include "Creature.hpp"

class Monster : public Creature
{
private:
    double attackChance_ = 0.5;
public:
    Monster() = default;
    Monster(std::string name);
    Monster(int armorPoints,
            int attackChance,
            int attackDamage,
            int healthPoints,
            int maxArmorPoints,
            int maxHealthPoints,
            std::string name);

    double getAttackChance() const;
};