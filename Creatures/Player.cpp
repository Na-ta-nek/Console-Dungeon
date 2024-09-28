#include "Player.hpp"

Player::Player(std::string name) : Creature(0, //armorPoints
                                            5, //AttackDamage
                                            100, //healthPoints
                                            100, //maxArmorPoints
                                            100, //maxHealthPoints
                                            name) {};

unsigned Player::getDungeonsCompleted() const { return dungeonsCompleted_; };
unsigned Player::getMobsKilled() const { return mobsKilled_; };
int Player::getNumberOfItemsInBackpack() const { return backpack_.size(); };
unsigned Player::getRoomsPassed() const { return roomsPassed_; };
void Player::increaseDungeonsCounter() { dungeonsCompleted_++; };
void Player::increaseMobsCounter() { mobsKilled_++; };
void Player::increaseRoomsCounter() { roomsPassed_++; };
bool Player::isBackpackEmpty() const { return backpack_.empty(); };

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

void Player::useItem(const int& index)
{
    backpack_[index]->use(this);
    backpack_.erase(backpack_.begin()+index);
}

void Player::useItem(const std::shared_ptr<Item>& item)
{
    item->use(this);
}