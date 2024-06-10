#pragma once
#include <iostream>
#include <stdexcept>

class InvalidCommandInAdmin : public std::runtime_error {
public:
    InvalidCommandInAdmin(const std::string& message)
        : std::runtime_error(message) {}
};