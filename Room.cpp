#include "Room.hpp"

Room::Room() = default;

Room::Room(int amountOfRoomsInDungeon,
           int difficultyLevel) : amountOfRoomsInDungeon_(amountOfRoomsInDungeon),
                                  difficultyLevel_(difficultyLevel)
{
    amountOfRoomsInDungeon_ += 1;
    monstersInitialization();
    lootInitialization();
}

Room::~Room() = default;

std::shared_ptr<Item> Room::getItem(const int& index) const
{
    return lootChest_[index];
}

std::vector<std::shared_ptr<Monster>> Room::getMonsters() const
{
    return monsters_;
}

int Room::getNumberOfItems() const {return lootChest_.size(); };

int Room::getNumberOfMonsters() const { return monsters_.size(); };

bool Room::hasRoomItems() const { return !lootChest_.empty(); };

bool Room::hasRoomMonsters() const { return !monsters_.empty(); };

void Room::lootInitialization()
{
    int itemsAmount = std::floor(((double) rand() / (RAND_MAX)) * 
                                     ROOM_CONFIG::MAX_ITEMS_IN_ROOM + 
                                     (difficultyLevel_ / 
                                     DUNGEON_CONFIG::MAX_ROOMS_IN_DUNGEON));
    for(int i = 0; i < itemsAmount; i++)
    {
        //TODO more items
        lootChest_.push_back(std::make_shared<Chestplate>());
    }
}

void Room::monstersInitialization()
{
    double levelFactor = ((double)(difficultyLevel_+1) / (double)amountOfRoomsInDungeon_);
    double randomFactor = ((((double) rand() / (RAND_MAX)) + levelFactor) / 2.2);
    int monstersAmount = std::floor(randomFactor * (double)(ROOM_CONFIG::MAX_MONSTERS_IN_ROOM+1));
    
    int monsterIndex = 0;
    for(int i = 0; i < monstersAmount; i++)
    {
        randomFactor = ((((double) rand() / (RAND_MAX)) + levelFactor) / 2);
        monsterIndex = std::floor(randomFactor * (double)ROOM_CONFIG::POSSIBLE_MONSTERS_CLASSES);
        monsters_.push_back(spawnMobByIndex(monsterIndex));
    }
}

void Room::printInformation() const
{
    if(!monsters_.empty())
    {
        
        std::cout << "-----------------------------------------------------------" << '\n';
        std::cout << std::setw(33) << std::right << "Enemies:" << '\n';
        for(auto monster : monsters_)
        {
            monster->printInformation();
        }
        if(!lootChest_.empty())
        {
            std::cout << "-----------------------------------------------------------" << '\n';
            std::cout << std::setw(33) << std::right << "Chest contains " << std::setw(1) << lootChest_.size() << " items!" << '\n';
        }
    }
    else
    {
        if(!lootChest_.empty())
        {
            std::cout << "-----------------------------------------------------------" << '\n';
            std::cout << std::setw(32) << std::right << "Loot:" << '\n';
            for(auto item : lootChest_)
            {
                item->printInformation();
            }
        }
    }
}

std::shared_ptr<Monster> Room::spawnMobByIndex(const int& index)
{
    switch (index) {
        case 0:
            return std::make_shared<Skeleton>();
        case 1:
            return std::make_shared<Zombie>();
        case 2:
            return std::make_shared<Orc>();
        case 3:
            return std::make_shared<Shaman>();
        case 4:
            return std::make_shared<Vampire>();
        case 5:
            return std::make_shared<DeathKnight>();
        case 6:
            return std::make_shared<Wizard>();
        case 7:
            return std::make_shared<Golem>();
        case 8:
            return std::make_shared<Dragon>();
        default:
            return nullptr;
    }
}

void Room::updateItemsInRoom(const int& index)
{
    if(lootChest_[index])
    {
        lootChest_.erase(lootChest_.begin()+index);
    }
}

void Room::updateMonstersInRoom()
{
    for(int i = 0; i < monsters_.size(); i++)
    {
        if(monsters_[i]->getHealthPoints() <= 0)
        {
            monsters_.erase(monsters_.begin()+i);
        }
    }
}