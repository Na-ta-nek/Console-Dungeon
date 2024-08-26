#include "Creature.hpp"

Creature::Creature(std::string name) : name_(name) {};

Creature::Creature(int armorPoints,
                   int attackDamage,
                   int healthPoints,
                   int maxArmorPoints,
                   int maxHealthPoints,
                   std::string name) : armorPoints_(armorPoints),
                                       attackDamage_(attackDamage),
                                       healthPoints_(healthPoints),
                                       maxArmorPoints_(maxArmorPoints),
                                       maxHealthPoints_(maxHealthPoints),
                                       name_(name) {};

void Creature::armorPointsDamage(const int& damage)
{
    if(armorPoints_ - damage < 0)
    {
        armorPoints_ = 0;
    }
    else
    {
        armorPoints_ -= damage;
    }
}

void Creature::healthPointsDamage(const int& damage)
{
    if(healthPoints_ - damage < 0)
    {
        healthPoints_ = 0;
    }
    else
    {
        healthPoints_ -= damage;
    }
}

int Creature::getArmorPoints() const { return armorPoints_; };
int Creature::getAttackDamage() const { return attackDamage_; };
int Creature::getHealthPoints() const { return healthPoints_; };
int Creature::getMaxArmorPoints() const { return maxArmorPoints_; };
int Creature::getMaxHealthPoints() const { return maxHealthPoints_; };
std::string Creature::getName() const { return name_; };

void Creature::printInformation() const
{
    std::cout << std::setw(20) << std::left << name_;
    std::cout << std::setw(17) << std::right << "Health: " << healthPoints_ << "/" << maxHealthPoints_;
    std::cout << std::setw(1) << " ";
    std::cout << "Armor: " << armorPoints_ << "/" << maxArmorPoints_ << '\n';
}