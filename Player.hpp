#pragma once
#include <iomanip>
#include <iostream>

class Player
{
private:
    int armorPoints_ = 0;
    unsigned dungeonsCompleted = 0;
    int healthPoints_ = 100;
    int maxArmorPoints_ = 100;
    int maxHealthPoints_ = 100;
    unsigned mobsKilled = 0;
    std::string name_ = "Player";
    unsigned roomsPassed = 0;
public:
    Player();
    Player(std::string name);
    ~Player();

    void increaseDungeonsCounter();
    void increaseRoomsCounter();
    int getArmorPoints() const;
    unsigned getDungeonsCompleted() const;
    int getHealthPoints() const;
    unsigned getMobsKilled() const;
    std::string getName() const;
    unsigned getRoomsPassed() const;
    void printInformation() const;
};
