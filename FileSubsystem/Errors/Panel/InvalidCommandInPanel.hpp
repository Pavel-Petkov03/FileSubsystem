#pragma once
#include <iostream>
#include <stdexcept>
#include "../../Utility/MyString.h"
class InvalidCommandInPanel : public std::runtime_error {
public:
    InvalidCommandInPanel(const char* message)
        : std::runtime_error(message) {}
};