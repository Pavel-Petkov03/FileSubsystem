#pragma once
#include <iostream>
#include <stdexcept>

class InvalidFileType : public std::runtime_error {
public:
    InvalidFileType(const std::string& message)
        : std::runtime_error(message) {}
};

class InvalidFileName : public std::runtime_error {
public:
    InvalidFileName(const std::string& message)
        : std::runtime_error(message) {}
};