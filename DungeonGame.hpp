#pragma once
#include <iostream>
#include <memory>
#include "Player.hpp"

class DungeonGame
{
private:
    std::shared_ptr<Player> player_ = nullptr;
public:
    DungeonGame();
    ~DungeonGame();

    void gameStart();
    void getUserNickname(std::string& name);
    void run();
};