#pragma once
#include <iostream>

#include "Monster.hpp"

class DeathKnight : public Monster
{
public:
    DeathKnight();

    void ability(const std::shared_ptr<Player>& player,
                 const std::vector<std::shared_ptr<Monster>>& monsters) override;
};