#include "Player.hpp"

Player::Player() {}

Player::Player(std::string name) : name_(name) {}

Player::~Player() = default;

void Player::increaseDungeonsCounter() { dungeonsCompleted++; };
void Player::increaseRoomsCounter() { roomsPassed++; };
int Player::getArmorPoints() const { return armorPoints_; };
unsigned Player::getDungeonsCompleted() const { return dungeonsCompleted; };
int Player::getHealthPoints() const { return healthPoints_; };
unsigned Player::getMobsKilled() const { return mobsKilled; };
std::string Player::getName() const { return name_; };
unsigned Player::getRoomsPassed() const { return roomsPassed; };

void Player::printInformation() const
{
    std::cout << "------------------------------------------------------------" << '\n';
    std::cout << std::setw(20) << std::left << name_;
    std::cout << std::setw(17) << std::right << "Health: " << healthPoints_ << "/" << maxHealthPoints_;
    std::cout << std::setw(1) << " ";
    std::cout << "Armor: " << armorPoints_ << "/" << maxArmorPoints_ << '\n';
}