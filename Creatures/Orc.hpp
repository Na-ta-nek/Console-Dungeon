#pragma once
#include <iostream>

#include "Monster.hpp"

class Orc : public Monster
{
public:
    Orc();

    void ability(const std::shared_ptr<Player>& player,
                 const std::vector<std::shared_ptr<Monster>>& monsters) override;
};