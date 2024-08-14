#include "DungeonGame.hpp"

DungeonGame::DungeonGame()
{}

DungeonGame::~DungeonGame()
{}

void DungeonGame::gameStart()
{
    std::string playerName{""};
    while(true)
    {
        getUserNickname(playerName);
        if(playerName.size()>50)
        {
            std::cout << "Your name should not be longer than 50 characters" << '\n';
            system("read -p 'Press Enter to continue...' var");
        }
        else
        {
            break;
        }
    }
    //TODO Need to create player and dungeon
}

void DungeonGame::getUserNickname(std::string& name)
{
    system("clear");
    std::cout << "What`s your name?" << '\n';
    std::cin >> name;
}

void DungeonGame::run()
{
    gameStart();    
}