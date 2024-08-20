#pragma once
#include <functional>
#include <iostream>

class Action
{
private:
    unsigned index_ = 1;
    std::string message_ = "Action";
    std::function<void()> function_{};
public:
    Action();
    Action(unsigned index, std::string message, std::function<void()> function);
    ~Action();

    std::function<void()> getFunction() const;
    void printInformation() const;
};