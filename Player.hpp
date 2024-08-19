#pragma once
#include <iostream>

class Player
{
private:
    std::string name_ = "Player";
    int healthPoints_ = 100;
    int armorPoints_ = 0;
public:
    Player();
    Player(std::string name);
    ~Player();

    std::string getName() const;
    int getHealthPoints() const;
    int getArmorPoints() const;
};
