#pragma once
#include <iostream>
#include <stdexcept>

class InvalidFileError : public std::runtime_error {
public:
    InvalidFileError(const char* message) : std::runtime_error(message) {}
};

class InvalidFileType : public InvalidFileError {
public:
    InvalidFileType(const char* message): InvalidFileError(message) {}
};

class InvalidFileName : public InvalidFileError {
public:
    InvalidFileName(const char* message): InvalidFileError(message) {}
};


class CircularFileError : public std::runtime_error {
public:
    CircularFileError(const char* message) : std::runtime_error(message) {}
};