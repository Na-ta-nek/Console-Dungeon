#pragma once
#include <functional>
#include <iostream>

class Action
{
private:
    std::function<void()> function_{};
    unsigned index_ = 1;
    std::string message_ = "Action";
public:
    Action();
    Action(unsigned index, std::string message, std::function<void()> function);
    ~Action();

    std::function<void()> getFunction() const;
    void printInformation() const;
};