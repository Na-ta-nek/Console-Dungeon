#pragma once
#include <iomanip>
#include <iostream>

class Monster
{
private:
    int armorPoints_ = 0;
    int attackDamage_ = 15;
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

    void armorPointsDamage(const int& damage);
    void healthPointsDamage(const int& damage);
    int getArmorPoints() const;
    int getAttackDamage() const;
    int getHealthPoints() const;
    int getMaxArmorPoints() const;
    int getMaxHealthPoints() const;
    void printInformation() const;
};