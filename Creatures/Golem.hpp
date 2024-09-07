#pragma once
#include <iostream>

#include "Monster.hpp"

class Golem : public Monster
{
public:
    Golem();
    ~Golem();

    virtual void ability(const std::shared_ptr<Player>& player,
                         const std::vector<std::shared_ptr<Monster>>& monsters) override;
};