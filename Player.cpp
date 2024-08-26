#include "Player.hpp"

Player::Player(std::string name) : Creature(0,
                                            30,
                                            100,
                                            100,
                                            100,
                                            name) {};

unsigned Player::getDungeonsCompleted() const { return dungeonsCompleted_; };
unsigned Player::getMobsKilled() const { return mobsKilled_; };
unsigned Player::getRoomsPassed() const { return roomsPassed_; };

void Player::increaseDungeonsCounter() { dungeonsCompleted_++; };
void Player::increaseMobsCounter() { mobsKilled_++; };
void Player::increaseRoomsCounter() { roomsPassed_++; };

void Player::printInformation() const
{
    std::cout << "------------------------------------------------------------" << '\n';
    std::cout << std::setw(34) << std::right << "Player:" << '\n';
    Creature::printInformation();
}