#pragma once
#include <iostream>

class Monster
{
private:
    int armorPoints_ = 0;
    int healthPoints_ = 100;
    int maxArmorPoints_ = 100;
    int maxHealthPoints_ = 100;
    std::string name_ = "Monster";
public:
    Monster();
    Monster(int armorPoints,
            int healthPoints,
            int maxArmorPoints,
            int maxHealthPoints,
            std::string name);
    Monster(std::string name);
    ~Monster();
};