#pragma once
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

#include "GameConfig.hpp"
#include "Monster.hpp"

class Room
{
private:
    int difficultyLevel_ = 0;
    std::vector<std::shared_ptr<Monster>> monsters_{};
public:
    Room();
    Room(int difficultyLevel);
    ~Room();

    void monstersInitialization();
    void printInformation() const;
};