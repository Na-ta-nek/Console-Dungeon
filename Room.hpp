#pragma once
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

#include "GameConfig.hpp"
#include "Creatures/DeathKnight.hpp"
#include "Creatures/Dragon.hpp"
#include "Creatures/Golem.hpp"
#include "Creatures/Monster.hpp"
#include "Creatures/Orc.hpp"
#include "Creatures/Shaman.hpp"
#include "Creatures/Skeleton.hpp"
#include "Creatures/Vampire.hpp"
#include "Creatures/Wizard.hpp"
#include "Creatures/Zombie.hpp"
#include "Items/Bandage.hpp"
#include "Items/Chestplate.hpp"
#include "Items/Dagger.hpp"
#include "Items/FirstAidKit.hpp"
#include "Items/Helmet.hpp"
#include "Items/Item.hpp"
#include "Items/Pill.hpp"
#include "Items/Shield.hpp"
#include "Items/Spear.hpp"
#include "Items/Sword.hpp"

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
    std::shared_ptr<Item> spawnItemByIndex(const int& index);
    std::shared_ptr<Monster> spawnMobByIndex(const int& index);
    void updateItemsInRoom(const int& index);
    void updateMonstersInRoom();
};