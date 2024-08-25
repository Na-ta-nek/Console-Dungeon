#include "Room.hpp"

Room::Room() = default;

Room::Room(int difficultyLevel) : difficultyLevel_(difficultyLevel)
{
    monstersInitialization();
}

Room::~Room() = default;

void Room::monstersInitialization()
{
    int monstersAmount = std::floor(((double) rand() / (RAND_MAX)) * 
                                     ROOM_CONFIG::MAX_MONSTERS_IN_ROOM + 
                                     (difficultyLevel_ / 
                                     DUNGEON_CONFIG::MAX_ROOMS_IN_DUNGEON));
                                     
    for(int i = 0; i < monstersAmount; i++)
    {
        monsters_.push_back(
            std::make_shared<Monster>(
                Monster(
                    "Zombie"
                )));
    }
}

void Room::printInformation() const
{
    if(!monsters_.empty())
    {
        
        std::cout << "------------------------------------------------------------" << '\n';
        std::cout << std::setw(34) << std::right << "Enemies:" << '\n';
        for(auto monster : monsters_)
        {
            monster->printInformation();
        }
    }
}