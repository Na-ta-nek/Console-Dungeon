#pragma once
#include <iomanip>
#include <iostream>

#include "Creature.hpp"

class Monster : public Creature
{
public:
    Monster() = default;
    Monster(std::string name);
    Monster(int armorPoints,
            int attackDamage,
            int healthPoints,
            int maxArmorPoints,
            int maxHealthPoints,
            std::string name);
};