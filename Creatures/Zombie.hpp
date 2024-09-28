#pragma once
#include <iostream>

#include "Monster.hpp"

class Zombie : public Monster
{
public:
    Zombie();

    void ability(const std::shared_ptr<Player>& player,
                 const std::vector<std::shared_ptr<Monster>>& monsters) override;
};