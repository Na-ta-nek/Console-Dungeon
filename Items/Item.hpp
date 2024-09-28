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
    Item() = default;
    Item(std::string name, int value);
    Item(const Item&) = default;
    Item(Item&&) = default;
    Item& operator=(const Item&) = default;
    Item& operator=(Item&&) = default;
    virtual ~Item() = 0;

    std::string getName() const;
    int getValue() const;
    virtual void printInformation() const;
    virtual void use(Player* player) = 0;
};