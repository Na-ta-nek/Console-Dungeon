#include "Player.hpp"

Player::Player() {}

Player::Player(std::string name) : name_(name) {}

Player::~Player() = default;

std::string Player::getName() const { return name_; };
int Player::getHealthPoints() const { return healthPoints_; };
int Player::getArmorPoints() const { return armorPoints_; };

void Player::printInformation() const
{
    std::cout << std::setw(20) << std::left << name_;
    std::cout << std::setw(17) << std::right << "Health: " << healthPoints_ << "/" << maxHealthPoints_;
    std::cout << std::setw(1) << " ";
    std::cout << "Armor: " << armorPoints_ << "/" << maxArmorPoints_ << '\n';
}