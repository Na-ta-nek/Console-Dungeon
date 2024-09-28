#include "Item.hpp"
#include "../Creatures/Player.hpp"

Item::Item(std::string name,
           int value) : name_(name),
                        value_(value) {};

Item::~Item() {};

std::string Item::getName() const { return name_; };
int Item::getValue() const { return value_; };

void Item::printInformation() const
{
    std::cout << std::setw(20) << std::left << name_;
    std::cout << std::setw(36) << std::right << "Value: " << std::setw(3) << value_ << '\n';
}