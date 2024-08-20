#pragma once
#include <iomanip>
#include <iostream>

class Player
{
private:
    int armorPoints_ = 0;
    int healthPoints_ = 100;
    int maxArmorPoints_ = 100;
    int maxHealthPoints_ = 100;
    std::string name_ = "Player";
public:
    Player();
    Player(std::string name);
    ~Player();

    std::string getName() const;
    int getHealthPoints() const;
    int getArmorPoints() const;
    void printInformation() const;
};
