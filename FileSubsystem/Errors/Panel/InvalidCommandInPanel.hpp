#pragma once
#include <iostream>
#include <stdexcept>

class InvalidCommandInPanel : public std::runtime_error {
public:
    InvalidCommandInPanel(const std::string& message)
        : std::runtime_error(message) {}
};