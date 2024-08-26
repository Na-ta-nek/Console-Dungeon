#include "Monster.hpp"

Monster::Monster(std::string name) : Creature(0,
                                              15,
                                              100,
                                              100,
                                              100,
                                              name) {};

Monster::Monster(int armorPoints,
                 int attackDamage,
                 int healthPoints,
                 int maxArmorPoints,
                 int maxHealthPoints,
                 std::string name) : Creature(armorPoints,
                                              attackDamage,
                                              healthPoints,
                                              maxArmorPoints,
                                              maxHealthPoints,
                                              name) {};