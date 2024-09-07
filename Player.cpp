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

bool Player::isBackpackFull() const
{
    return backpack_.size() >= PLAYER_CONFIG::MAX_ITEMS_IN_BACKPACK;
}

void Player::printInformation() const
{
    std::cout << "-----------------------------------------------------------" << '\n';
    std::cout << std::setw(33) << std::right << "Player:" << '\n';
    Creature::printInformation();
    if(!backpack_.empty())
    {
        std::cout << std::setw(34) << std::right << "Backpack:" << '\n';
        for(auto item : backpack_)
        {
            item->printInformation();
        }
    }
}

void Player::putItemInBackpack(const std::shared_ptr<Item>& item)
{
    backpack_.push_back(item);
}

void Player::useItem(const std::shared_ptr<Item>& item)
{
    item->use(*this);
}