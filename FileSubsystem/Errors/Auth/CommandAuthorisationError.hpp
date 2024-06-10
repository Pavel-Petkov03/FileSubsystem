#include <iostream>
#include <stdexcept>

class CommandAuthorisationError : public std::runtime_error {
public:
    CommandAuthorisationError(const std::string& message)
        : std::runtime_error(message) {}
};