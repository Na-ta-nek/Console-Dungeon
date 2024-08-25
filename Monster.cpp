#include "Monster.hpp"

Monster::Monster() {};

Monster::Monster(int armorPoints,
            int healthPoints,
            int maxArmorPoints,
            int maxHealthPoints,
            std::string name) : armorPoints_(armorPoints),
                                healthPoints_(healthPoints),
                                maxArmorPoints_(maxArmorPoints),
                                maxHealthPoints_(maxHealthPoints),
                                name_(name) {};

Monster::Monster(std::string name) : armorPoints_(0),
                                     healthPoints_(100),
                                     maxArmorPoints_(100),
                                     maxHealthPoints_(100),
                                     name_(name) {};

Monster::~Monster() = default;

void Monster::armorPointsDamage(const int& damage)
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

void Monster::healthPointsDamage(const int& damage)
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

int Monster::getArmorPoints() const { return armorPoints_; };
int Monster::getHealthPoints() const { return healthPoints_; };
int Monster::getMaxArmorPoints() const { return maxArmorPoints_; };

void Monster::printInformation() const
{
    std::cout << std::setw(20) << std::left << name_;
    std::cout << std::setw(17) << std::right << "Health: " << healthPoints_ << "/" << maxHealthPoints_;
    std::cout << std::setw(1) << " ";
    std::cout << "Armor: " << armorPoints_ << "/" << maxArmorPoints_ << '\n';
}