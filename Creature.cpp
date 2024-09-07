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

void Creature::attack(const std::shared_ptr<Creature>& target)
{
    isDefending_ = false;
    int AttackDamage = getAttackDamage();
    if(!target->getIsDefending())
    {
        AttackDamage += rand()%getAttackDamage();
    }
    int targetArmorPoints = target->getArmorPoints();
    int targetHealthPoints = target->getHealthPoints();
    int maxTargetArmorPoints = target->getMaxArmorPoints();
    double armorAbsorption = targetArmorPoints / maxTargetArmorPoints;
    int armorDamageDealt = std::round(AttackDamage * armorAbsorption);
    int healthDamageDealt = AttackDamage - armorDamageDealt;
    target->armorPointsDamage(armorDamageDealt);
    target->healthPointsDamage(healthDamageDealt);
}

void Creature::defend() { isDefending_ = true; };

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
bool Creature::getIsDefending() const { return isDefending_; };
int Creature::getMaxArmorPoints() const { return maxArmorPoints_; };
int Creature::getMaxHealthPoints() const { return maxHealthPoints_; };
std::string Creature::getName() const { return name_; };

void Creature::increaseHealthPoints(const int& amount)
{
    if(healthPoints_ + amount > maxHealthPoints_)
    {
        healthPoints_ = maxHealthPoints_;
    }
    else
    {
        healthPoints_ += amount;
    }
}

void Creature::printInformation() const
{
    std::cout << std::left << std::setw(20) << name_;
    std::cout << std::right << std::setw(17) << "Health: " << std::setw(3) << healthPoints_ << "/" << maxHealthPoints_ << " " << "Armor: " << std::setw(3) << armorPoints_ << "/" << maxArmorPoints_ << '\n';
}

void Creature::resetHealthPoints() { healthPoints_ = maxHealthPoints_; };