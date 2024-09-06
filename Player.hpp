#pragma once
#include <iomanip>
#include <iostream>
#include <memory>

#include "Creature.hpp"
#include "Item.hpp"

class Player : public Creature
{
private:
    unsigned dungeonsCompleted_ = 0;
    unsigned mobsKilled_ = 0;
    unsigned roomsPassed_ = 0;
public:
    Player() = default;
    Player(std::string name);

    unsigned getDungeonsCompleted() const;
    unsigned getMobsKilled() const;
    unsigned getRoomsPassed() const;
    void increaseDungeonsCounter();
    void increaseMobsCounter();
    void increaseRoomsCounter();
    void printInformation() const;
    void useItem(const std::shared_ptr<Item>& item);
};
