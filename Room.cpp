#include "Room.hpp"

Room::Room() = default;

Room::Room(int amountOfRoomsInDungeon,
           int difficultyLevel) : amountOfRoomsInDungeon_(amountOfRoomsInDungeon),
                                  difficultyLevel_(difficultyLevel)
{
    amountOfRoomsInDungeon_ += 1;
    monsters_.reserve(ROOM_CONFIG::MAX_MONSTERS_IN_ROOM);
    monstersInitialization();
    lootChest_.reserve(ROOM_CONFIG::MAX_ITEMS_IN_ROOM);
    lootInitialization();
}

Room::~Room() = default;

std::shared_ptr<Item> Room::getItem(const int& index) const
{
    return lootChest_[index];
}

const std::vector<std::shared_ptr<Monster>>& Room::getMonsters() const
{
    return monsters_;
}

int Room::getNumberOfItems() const {return lootChest_.size(); };

int Room::getNumberOfMonsters() const { return monsters_.size(); };

bool Room::hasRoomItems() const { return !lootChest_.empty(); };

bool Room::hasRoomMonsters() const { return !monsters_.empty(); };

void Room::lootInitialization()
{
    double levelFactor = static_cast<double>(difficultyLevel_) / static_cast<double>(amountOfRoomsInDungeon_);
    double randomFactor = std::abs(levelFactor - static_cast<double>(rand()) / (RAND_MAX));
    int itemsAmount = static_cast<int>(std::round(randomFactor * static_cast<double>(ROOM_CONFIG::MAX_ITEMS_IN_ROOM)));
    
    double classRandomFactor = 0.0;
    int itemIndex = 0;
    for(int i = 0; i < itemsAmount; i++)
    {
        randomFactor = ((static_cast<double>(rand()) / (RAND_MAX)) + levelFactor) / 2.0;
        classRandomFactor = static_cast<double>(rand()) / (RAND_MAX);
        if(classRandomFactor < 0.5)
        {
            if(randomFactor < 0.5)
            {
                itemIndex = 0;
            }
            else if(randomFactor < 0.85)
            {
                itemIndex = 1;
            }
            else
            {
                itemIndex = 2;
            }
        }
        else if(classRandomFactor < 0.85)
        {
            if(randomFactor < 0.5)
            {
                itemIndex = 3;
            }
            else if(randomFactor < 0.85)
            {
                itemIndex = 4;
            }
            else
            {
                itemIndex = 5;
            }
        }
        else
        {
            if(randomFactor < 0.5)
            {
                itemIndex = 6;
            }
            else if(randomFactor < 0.85)
            {
                itemIndex = 7;
            }
            else
            {
                itemIndex = 8;
            }
        }
        lootChest_.emplace_back(spawnItemByIndex(itemIndex));
    }
}

void Room::monstersInitialization()
{
    double levelFactor = static_cast<double>(difficultyLevel_) / static_cast<double>(amountOfRoomsInDungeon_);
    double randomFactor = std::abs(levelFactor - static_cast<double>(rand()) / (RAND_MAX));
    int monstersAmount = static_cast<int>(std::round(randomFactor * static_cast<double>(ROOM_CONFIG::MAX_MONSTERS_IN_ROOM)));
    
    int monsterIndex = 0;
    double classRatio = 1.0 - ROOM_CONFIG::CLASS_RATIO;
    double classFactor = 0.0;
    for(int i = 0; i < monstersAmount; i++)
    {
        randomFactor = ((static_cast<double>(rand()) / (RAND_MAX)) + levelFactor) / 2.0;
        classFactor = 1.0 - classRatio;

        for(monsterIndex = 0; monsterIndex < ROOM_CONFIG::POSSIBLE_MONSTERS_CLASSES; monsterIndex++)
        {
            randomFactor -= classFactor;
            if(randomFactor <= 0)
            {
                break;
            }
            else
            {
                classFactor *= classRatio;
            }
        }
        monsters_.emplace_back(spawnMobByIndex(monsterIndex));
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

std::shared_ptr<Item> Room::spawnItemByIndex(const int& index)
{
    switch (index) {
        case 0:
            return std::make_shared<Pill>();
        case 1:
            return std::make_shared<Bandage>();
        case 2:
            return std::make_shared<FirstAidKit>();
        case 3:
            return std::make_shared<Shield>();
        case 4:
            return std::make_shared<Helmet>();
        case 5:
            return std::make_shared<Chestplate>();
        case 6:
            return std::make_shared<Dagger>();
        case 7:
            return std::make_shared<Spear>();
        case 8:
            return std::make_shared<Sword>();
        default:
            return nullptr;
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
    std::erase_if(monsters_,
                  [](const auto& monster){ return monster->getHealthPoints() <= 0; });
}