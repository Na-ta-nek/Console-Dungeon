#include "Player.hpp"

Player::Player() {}

Player::Player(std::string name) : name_(name) {}

Player::~Player() = default;

void Player::armorPointsDamage(const int& damage)
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

void Player::healthPointsDamage(const int& damage)
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

void Player::increaseDungeonsCounter() { dungeonsCompleted_++; };
void Player::increaseMobsCounter() { mobsKilled_++; };
void Player::increaseRoomsCounter() { roomsPassed_++; };
int Player::getArmorPoints() const { return armorPoints_; };
int Player::getAttackDamage() const { return attackDamage_; };
unsigned Player::getDungeonsCompleted() const { return dungeonsCompleted_; };
int Player::getHealthPoints() const { return healthPoints_; };
int Player::getMaxArmorPoints() const { return maxArmorPoints_; };
unsigned Player::getMobsKilled() const { return mobsKilled_; };
std::string Player::getName() const { return name_; };
unsigned Player::getRoomsPassed() const { return roomsPassed_; };

void Player::printInformation() const
{
    std::cout << "------------------------------------------------------------" << '\n';
    std::cout << std::setw(34) << std::right << "Player:" << '\n';
    std::cout << std::setw(20) << std::left << name_;
    std::cout << std::setw(17) << std::right << "Health: " << healthPoints_ << "/" << maxHealthPoints_;
    std::cout << std::setw(1) << " ";
    std::cout << "Armor: " << armorPoints_ << "/" << maxArmorPoints_ << '\n';
}