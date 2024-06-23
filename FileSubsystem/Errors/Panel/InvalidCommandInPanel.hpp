#pragma once
#include <iostream>
#include <stdexcept>
class InvalidCommandInPanel : public std::runtime_error {
public:
    InvalidCommandInPanel(const char* message)
        : std::runtime_error(message) {}
};

class EscapePanelError : public std::runtime_error {
public:
    EscapePanelError(const char* message)
        : std::runtime_error(message) {}
};