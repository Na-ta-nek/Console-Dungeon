#include "DungeonGame.hpp"

DungeonGame::DungeonGame()
{}

DungeonGame::~DungeonGame()
{}

void DungeonGame::dungeonCompletedCase()
{
    system("clear");
    std::cout << "Congrats! You managed to completed this dungeon!" << '\n';
    startAgainDialogue([this](){ return this->dungeonCompletedCase(); });
}

void DungeonGame::dungeonInitialization(const int& number)
{
    currentRoom_ = 0;
    for(int i = 0; i < number; i++)
    {
        //TODO add loot
        dungeon_.push_back(std::make_shared<Room>(Room(i)));
    }
}

void DungeonGame::gamePlay()
{
    system("clear");
    printInformation();

    possibleActionsUpdate();
    printPossibleActions();

    std::cin >> keyPressed_;
    if(keyPressed_ > 48 && keyPressed_ <= 48+possibleActions_.size())
    {
        std::function<void()> functionToCall = possibleActions_[keyPressed_-49].getFunction();
        functionToCall();
    }
    else
    {
        gamePlay();
    }
}

void DungeonGame::gameStart()
{
    std::string playerName{""};
    while(true)
    {
        getUserNickname(playerName);
        if(playerName.size()>20)
        {
            std::cout << "Your name should not be longer than 20 characters" << '\n';
            system("read -p 'Press Enter to continue...' var");
        }
        else
        {
            break;
        }
    }
    player_ = std::make_shared<Player>(Player(playerName));

    dungeonInitialization((rand()%DUNGEON_CONFIG::MAX_ROOMS_IN_DUNGEON) + 1);
    gamePlay();
}

std::shared_ptr<Player> DungeonGame::getPlayer() { return player_; };

void DungeonGame::getUserNickname(std::string& name)
{
    system("clear");
    std::cout << "What`s your name?" << '\n';
    std::cin >> name;
}

void DungeonGame::monstersAttackAction()
{
    int monstersInRoom = dungeon_[currentRoom_]->getNumberOfMonsters();
    for(int i = 0; i < monstersInRoom; i++)
    {
        auto monster = dungeon_[currentRoom_]->getMonster(i);

        if(((double) rand() / (RAND_MAX)) < monster->getAttackChance())
        {
            monster->attack(player_);
        }
        else
        {
            monster->defend();
        }
        if(player_->getHealthPoints() <= 0)
        {
            system("clear");
            printInformation();
            std::cout << "You have died!" << '\n';
            system("read -p 'Press Enter to continue...' var");
            printEndGameStats();
            player_.reset();
            break;
        }
    }
}

void DungeonGame::playerAttackAction()
{
    if(dungeon_[currentRoom_]->getNumberOfMonsters() > 1)
    {
        system("clear");
        printInformation();
        std::cout << "Choose enemy to attack by entering index of the enemy" << '\n';
        std::cin >> keyPressed_;
    }
    else
    {
        keyPressed_ = 49;
    }
    int index = (int) keyPressed_ - 48;
    if(index > 0 && 
       index <= dungeon_[currentRoom_]->getNumberOfMonsters())
    {
        auto target = dungeon_[currentRoom_]->getMonster(index-1);
        player_->attack(target);
        if(target->getHealthPoints() <= 0)
        {
            player_->increaseMobsCounter();
        }
        dungeon_[currentRoom_]->updateMonstersInRoom();
        monstersAttackAction();
    }
    if(player_)
    {
        gamePlay();
    }
}

void DungeonGame::playerDefendAction()
{
    player_->defend();
    monstersAttackAction();
    if(player_)
    {
        gamePlay();
    }
}

void DungeonGame::possibleActionsUpdate()
{
    possibleActions_.clear();
    unsigned index = 1;
    //TODO item usage
    if(!dungeon_[currentRoom_]->hasRoomMonsters())
    {
        if(dungeon_[currentRoom_]->hasRoomItems())
        {
            possibleActions_.push_back(Action(index,
                                          "Use item",
                                          [this](){ this->useItemAction(); }));
            index++;
            //TODO adding item to backpack
        }
        possibleActions_.push_back(Action(index,
                                          "Go to next room",
                                          [this](){ this->switchToNextRoomAction(); }));
        index++;
    }
    else
    {
        possibleActions_.push_back(Action(index,
                                          "Attack",
                                          [this](){ this->playerAttackAction(); }));
        index++;
        possibleActions_.push_back(Action(index,
                                          "Defend",
                                          [this](){ this->playerDefendAction(); }));
        index++;
    }

    possibleActions_.push_back(Action(index,
                                      "Run away",
                                      [this](){ this->runAwayAction(); }));
    index++;
}

void DungeonGame::printEndGameStats()
{
    system("clear");
    std::cout << "Brave " << player_->getName() << "!" << '\n';
    std::cout << "You have slayed " << player_->getMobsKilled() << " mobs!" << '\n';
    std::cout << "You have passed " << player_->getRoomsPassed() << " rooms!" << '\n';
    std::cout << "You have completed " << player_->getDungeonsCompleted() << " dungeons!" << '\n';
    std::cout << "Thanks for your game! Bye." << '\n';
}

void DungeonGame::printInformation() const
{
    std::cout << std::setw(34) << std::right << "Room nr " << currentRoom_+1 << '\n';
    dungeon_[currentRoom_]->printInformation();
    player_->printInformation();
    std::cout << "------------------------------------------------------------" << '\n';
}

void DungeonGame::printPossibleActions() const
{
    if(possibleActions_.size() > 0)
    {
        for(auto element : possibleActions_)
        {
            element.printInformation();
        }
    }
}

void DungeonGame::run()
{
    gameStart();    
}

void DungeonGame::runAwayAction()
{
    system("clear");
    std::cout << "You escaped the dungeon safe and sound!" << '\n';
    startAgainDialogue([this](){ return this->runAwayAction(); });
}

void DungeonGame::startAgainDialogue(std::function<void()> function)
{
    std::cout << "Do you want to enter another dungeon?" << '\n';
    std::cout << "1. Yes" << '\n';
    std::cout << "2. No" << '\n';
    std::cin >> keyPressed_;
    if(keyPressed_ == 49) // '1'
    {
        dungeon_.clear();
        dungeonInitialization((rand()%10) + 1);
        player_->resetHealthPoints();
        gamePlay();
    }
    else if(keyPressed_ == 50) // '2'
    {
        printEndGameStats();
    }
    else
    {
        function();
    }
}

void DungeonGame::switchToNextRoomAction()
{
    if(currentRoom_+1 > dungeon_.size()-1)
    {
        player_->increaseRoomsCounter();
        player_->increaseDungeonsCounter();
        dungeonCompletedCase();
    }
    else
    {
        player_->increaseRoomsCounter();
        currentRoom_++;
        gamePlay();
    }
}

void DungeonGame::useItemAction()
{
    if(dungeon_[currentRoom_]->getNumberOfItems() > 1)
    {
        system("clear");
        printInformation();
        std::cout << "Choose item to use by entering index of the item" << '\n';
        std::cin >> keyPressed_;
    }
    else
    {
        keyPressed_ = 49;
    }
    int index = (int) keyPressed_ - 48;
    if(index > 0 && 
       index <= dungeon_[currentRoom_]->getNumberOfItems())
    {
        auto item = dungeon_[currentRoom_]->getItem(index-1);
        player_->useItem(item);
        dungeon_[currentRoom_]->updateItemsInRoom(index-1);
    }
    gamePlay();
}