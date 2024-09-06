#pragma once
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

#include "GameConfig.hpp"
#include "Item.hpp"
#include "Monster.hpp"

class Room
{
private:
    int difficultyLevel_ = 0;
    std::vector<std::shared_ptr<Monster>> monsters_{};
    std::vector<std::shared_ptr<Item>> lootChest_{};
public:
    Room();
    Room(int difficultyLevel);
    ~Room();

    std::shared_ptr<Item> getItem(const int& index) const;
    std::shared_ptr<Monster> getMonster(const int& index) const;
    int getNumberOfItems() const;
    int getNumberOfMonsters() const;
    bool hasRoomItems() const;
    bool hasRoomMonsters() const;
    void lootInitialization();
    void monstersInitialization();
    void printInformation() const;
    void updateItemsInRoom(const int& index);
    void updateMonstersInRoom();
};