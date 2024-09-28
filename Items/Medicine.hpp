#pragma once

#include <iostream>

#include "Item.hpp"
#include "../Creatures/Player.hpp"

class Medicine : public Item
{
public:
    Medicine(std::string name_, int value_);

    void printInformation() const override;
    void use(Player* player) override;
};