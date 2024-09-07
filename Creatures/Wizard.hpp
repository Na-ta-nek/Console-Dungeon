#pragma once
#include <iostream>

#include "Monster.hpp"

class Wizard : public Monster
{
public:
    Wizard();
    ~Wizard();

    virtual void ability(const std::shared_ptr<Player>& player,
                         const std::vector<std::shared_ptr<Monster>>& monsters) override;
};