#pragma once
#include <iomanip>
#include <iostream>
#include <memory>

class Player;

class Item
{
private:
    std::string name_ = "Item";
    int value_ = 40;
public:
    Item();
    Item(std::string name, int value);
    ~Item();

    void printInformation() const;
    void use(Player& player);
};