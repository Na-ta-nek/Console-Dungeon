#pragma once
#include <iostream>

#include "Monster.hpp"

class Vampire : public Monster
{
public:
    Vampire();
    ~Vampire();

    virtual void ability(const std::shared_ptr<Player>& player,
                         const std::vector<std::shared_ptr<Monster>>& monsters) override;
};