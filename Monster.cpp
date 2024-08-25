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

void Monster::printInformation() const
{
    std::cout << std::setw(20) << std::left << name_;
    std::cout << std::setw(17) << std::right << "Health: " << healthPoints_ << "/" << maxHealthPoints_;
    std::cout << std::setw(1) << " ";
    std::cout << "Armor: " << armorPoints_ << "/" << maxArmorPoints_ << '\n';
}