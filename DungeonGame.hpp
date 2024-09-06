#pragma once
#include <cmath>
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
    unsigned currentRoom_ = 0;
    std::vector<std::shared_ptr<Room>> dungeon_{};
    char keyPressed_ = ' ';
    std::shared_ptr<Player> player_ = nullptr;
    std::vector<Action> possibleActions_{};

public:
    DungeonGame();
    ~DungeonGame();

    void dungeonCompletedCase();
    void dungeonInitialization(const int& number);
    void gamePlay();
    void gameStart();
    std::shared_ptr<Player> getPlayer();
    void getUserNickname(std::string& name);
    void monstersAttackAction();
    void playerAttackAction();
    void playerDefendAction();
    void possibleActionsUpdate();
    void printEndGameStats();
    void printInformation() const;
    void printPossibleActions() const;
    void run();
    void runAwayAction();
    void startAgainDialogue(std::function<void()> function);
    void switchToNextRoomAction();
    void useItemAction();
};