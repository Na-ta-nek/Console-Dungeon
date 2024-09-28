#pragma once
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

#include "Creature.hpp"
#include "../GameConfig.hpp"
#include "../Items/Item.hpp"

class Player : public Creature
{
private:
    std::vector<std::shared_ptr<Item>> backpack_{};
    unsigned dungeonsCompleted_ = 0;
    unsigned mobsKilled_ = 0;
    unsigned roomsPassed_ = 0;
public:
    Player() = default;
    Player(std::string name);

    unsigned getDungeonsCompleted() const;
    unsigned getMobsKilled() const;
    int getNumberOfItemsInBackpack() const;
    unsigned getRoomsPassed() const;
    void increaseDungeonsCounter();
    void increaseMobsCounter();
    void increaseRoomsCounter();
    bool isBackpackEmpty() const;
    bool isBackpackFull() const;
    void printInformation() const;
    void putItemInBackpack(const std::shared_ptr<Item>& item);
    void useItem(const int& index);
    void useItem(const std::shared_ptr<Item>& item);
};
