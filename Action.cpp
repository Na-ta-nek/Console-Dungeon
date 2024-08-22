#include "Action.hpp"

Action::Action() = default;

Action::Action(unsigned index,
               std::string message,
               std::function<void()> function) : index_(index),
                                                 message_(message),
                                                 function_(function) {}

Action::~Action() = default;

std::function<void()> Action::getFunction() const { return function_; };

void Action::printInformation() const
{
    std::cout << index_ << ". " << message_ << '\n';
}