#include "Item.hpp"
#include "Player.hpp"

Item::Item() = default;

Item::Item(std::string name,
           int value) : name_(name),
                        value_(value) {};

Item::~Item() = default;

void Item::printInformation() const
{
    std::cout << std::setw(20) << std::left << name_;
    std::cout << std::setw(36) << std::right << "Value: " << std::setw(3) << value_ << '\n';
}

void Item::use(Player& player)
{
    player.increaseHealthPoints(value_);
}