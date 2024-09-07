#pragma once
#include <cmath>
#include <iomanip>
#include <iostream>
#include <memory>

class Creature
{
private:
    int armorPoints_ = 0;
    int attackDamage_ = 0;
    int healthPoints_ = 100;
    bool isDefending_ = true;
    int maxArmorPoints_ = 100;
    int maxHealthPoints_ = 100;
    std::string name_ = "Creature";
public:
    Creature() = default;
    Creature(std::string name);
    Creature(int armorPoints,
             int attackDamage,
             int healthPoints,
             int maxArmorPoints,
             int maxHealthPoints,
             std::string name);
    Creature(const Creature&) = default;
    Creature(Creature&&) = default;
    Creature& operator=(const Creature&) = default;
    Creature& operator=(Creature&&) = default;
    virtual ~Creature() = default;

    void armorPointsDamage(const int& damage);
    void attack(const std::shared_ptr<Creature>& target,
                const int& damage);
    void defend();
    void healthPointsDamage(const int& damage);
    int getArmorPoints() const;
    int getAttackDamage() const;
    int getHealthPoints() const;
    bool getIsDefending() const;
    int getMaxArmorPoints() const;
    int getMaxHealthPoints() const;
    std::string getName() const;
    void increaseArmorPoints(const int& amount);
    void increaseHealthPoints(const int& amount);
    void printInformation() const;
    void resetHealthPoints();
};