#pragma once
#include <iostream>
#include <cstdlib>

class DungeonGame
{
public:
    DungeonGame();
    ~DungeonGame();

    void gameStart();
    void getUserNickname(std::string& name);
    void run();
};