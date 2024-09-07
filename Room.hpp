#pragma once
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

#include "DeathKnight.hpp"
#include "Dragon.hpp"
#include "Golem.hpp"
#include "GameConfig.hpp"
#include "Item.hpp"
#include "Monster.hpp"
#include "Orc.hpp"
#include "Shaman.hpp"
#include "Skeleton.hpp"
#include "Vampire.hpp"
#include "Wizard.hpp"
#include "Zombie.hpp"

class Room
{
private:
    int amountOfRoomsInDungeon_ = 0;
    int difficultyLevel_ = 0;
    std::vector<std::shared_ptr<Monster>> monsters_{};
    std::vector<std::shared_ptr<Item>> lootChest_{};
public:
    Room();
    Room(int amountOfRoomsInDungeon, int difficultyLevel);
    ~Room();

    std::shared_ptr<Item> getItem(const int& index) const;
    std::vector<std::shared_ptr<Monster>> getMonsters() const;
    int getNumberOfItems() const;
    int getNumberOfMonsters() const;
    bool hasRoomItems() const;
    bool hasRoomMonsters() const;
    void lootInitialization();
    void monstersInitialization();
    void printInformation() const;
    std::shared_ptr<Monster> spawnMobByIndex(const int& index);
    void updateItemsInRoom(const int& index);
    void updateMonstersInRoom();
};