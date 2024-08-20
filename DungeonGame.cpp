#include "DungeonGame.hpp"

DungeonGame::DungeonGame()
{}

DungeonGame::~DungeonGame()
{}

void DungeonGame::dungeonInitialization(const int& number)
{
    for(int i = 0; i < number; i++)
    {
        dungeon_.push_back(std::make_shared<Room>(Room()));
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

    srand(time(0));
    dungeonInitialization((rand()%10) + 1);
    gamePlay();
}

void DungeonGame::getUserNickname(std::string& name)
{
    system("clear");
    std::cout << "What`s your name?" << '\n';
    std::cin >> name;
}

void DungeonGame::possibleActionsUpdate()
{
    possibleActions_.clear();
    unsigned index = 1;
    //TODO monsters, loot, item usage

    possibleActions_.push_back(Action(index,
                                      "Go to next room",
                                      [this](){ this->switchToNextRoomAction(); }));
    index++;
    possibleActions_.push_back(Action(index,
                                      "Run away",
                                      [this](){ this->runAwayAction(); }));
    index++;
}

void DungeonGame::printInformation() const
{
    std::cout << std::setw(34) << std::right << "Room nr " << currentRoom_+1 << '\n';
    std::cout << "------------------------------------------------------------" << '\n';
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
    //TODO end of dungeon defeat, want to start new dungeon
    std::cout << "Dead end" << '\n';
}

void DungeonGame::switchToNextRoomAction()
{
    if(currentRoom_+1 > dungeon_.size())
    {
        //TODO end of dungeon victory, want to start new dungeon
        std::cout << "\n";
    }
    else
    {
        currentRoom_++;
        gamePlay();
    }
}