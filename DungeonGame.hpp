#pragma once
#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>

#include "Player.hpp"
#include "Room.hpp"

class DungeonGame
{
private:
    std::vector<std::shared_ptr<Room>> dungeon_{};
    std::shared_ptr<Player> player_ = nullptr;

public:
    DungeonGame();
    ~DungeonGame();

    void dungeonInitialization(const int& number);
    void gameStart();
    void getUserNickname(std::string& name);
    void run();
};