#include "Player.hpp"

Player::Player() {}

Player::Player(std::string name) : name_(name) {}

Player::~Player() = default;

std::string Player::getName() const { return name_; };
int Player::getHealthPoints() const { return healthPoints_; };
int Player::getArmorPoints() const { return armorPoints_; };