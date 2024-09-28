#pragma once
#include <iostream>

#include "Monster.hpp"

class Shaman : public Monster
{
public:
    Shaman();

    void ability(const std::shared_ptr<Player>& player,
                 const std::vector<std::shared_ptr<Monster>>& monsters) override;
};