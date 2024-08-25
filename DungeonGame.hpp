#pragma once
#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>

#include "Action.hpp"
#include "GameConfig.hpp"
#include "Player.hpp"
#include "Room.hpp"

class DungeonGame
{
private:
    std::vector<std::shared_ptr<Room>> dungeon_{};
    std::shared_ptr<Player> player_ = nullptr;
    std::vector<Action> possibleActions_{};
    unsigned currentRoom_ = 0;
    char keyPressed_ = ' ';

public:
    DungeonGame();
    ~DungeonGame();

    void dungeonCompletedCase();
    void dungeonInitialization(const int& number);
    void gamePlay();
    void gameStart();
    void getUserNickname(std::string& name);
    void possibleActionsUpdate();
    void printEndGameStats();
    void printInformation() const;
    void printPossibleActions() const;
    void run();
    void runAwayAction();
    void startAgainDialogue(std::function<void()> function);
    void switchToNextRoomAction();
};