#include "Medicine.hpp"

Medicine::Medicine(std::string name_,
                   int value_) : Item(name_, value_) {};

void Medicine::printInformation() const
{
    std::cout << std::setw(20) << std::left << getName();
    std::cout << std::setw(34) << std::right << "+" << std::setw(3) << getValue() << "HP" << '\n';
}

void Medicine::use(Player* player)
{
    player->increaseHealthPoints(getValue());
}