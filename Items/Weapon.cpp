#include "Weapon.hpp"

Weapon::Weapon(std::string name_,
               int value_) : Item(name_, value_) {};

void Weapon::printInformation() const
{
    std::cout << std::setw(20) << std::left << getName();
    std::cout << std::setw(36) << std::right << "Damage: " << std::setw(3) << getValue() << '\n';
}

void Weapon::use(Player* player)
{
    player->setAttackDamage(getValue());
}