#include "Player.hpp"

Player::Player(std::string name) : Creature(0, //armorPoints
                                            5, //AttackDamage
                                            100, //healthPoints
                                            100, //maxArmorPoints
                                            100, //maxHealthPoints
                                            name) { backpack_.reserve(PLAYER_CONFIG::MAX_ITEMS_IN_BACKPACK); };

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
    std::cout << std::left << std::setw(20) << getName();
    std::cout << std::right << std::setw(32) << "Damage: " << std::setw(7) << getAttackDamage() << "\n";
    std::cout << std::right << std::setw(52) << "Health: " << std::setw(3) << getHealthPoints() << "/" << std::setw(3) <<  getMaxHealthPoints() << "\n";
    std::cout << std::right << std::setw(52) << "Armor: " << std::setw(3) << getArmorPoints() << "/" << std::setw(3) << getMaxArmorPoints() << '\n';
    if(!backpack_.empty())
    {
        std::cout << "\n";
        std::cout << std::setw(34) << std::right << "Backpack:" << '\n';
        for(auto item : backpack_)
        {
            item->printInformation();
        }
    }
}

void Player::putItemInBackpack(const std::shared_ptr<Item>& item)
{
    backpack_.emplace_back(item);
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