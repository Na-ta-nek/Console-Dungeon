#include "Gear.hpp"

Gear::Gear(std::string name_,
           int value_) : Item(name_, value_) {};

void Gear::printInformation() const
{
    std::cout << std::setw(20) << std::left << getName();
    std::cout << std::setw(30) << std::right << "+" << std::setw(3) << getValue() << " Armor" << '\n';
}

void Gear::use(Player* player)
{
    player->increaseArmorPoints(getValue());
}