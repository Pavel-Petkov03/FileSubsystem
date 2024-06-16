#include <iostream>
#include <stdexcept>
#pragma once
class CommandAuthorisationError : public std::runtime_error {
public:
    CommandAuthorisationError(const std::string& message)
        : std::runtime_error(message) {}
};

class RedirectError : public std::runtime_error {
public:
    RedirectError(const std::string& message)
        : std::runtime_error(message) {}
};

class UserAuthenticationRedirectError : public RedirectError {
public:
    UserAuthenticationRedirectError(const std::string& message)
        : RedirectError(message) {}
};

class AdminPanelRedirectError : public RedirectError {
public:
    AdminPanelRedirectError(const std::string& message)
        : RedirectError(message) {}
};

class AdminAuthenticationRedirectError : public RedirectError {
public:
    AdminAuthenticationRedirectError(const std::string& message)
        : RedirectError(message) {}
};

class UserInvalidCredentials : public std::runtime_error {
public:
    UserInvalidCredentials(const std::string& message)
        : std::runtime_error(message) {}
};


class UserNotInDatabaseException : public std::runtime_error {
public:
    UserNotInDatabaseException(const std::string& message)
        : std::runtime_error(message) {}
};