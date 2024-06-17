#include <iostream>
#include <stdexcept>
#include "../../Utility/MyString.h"
#pragma once
class CommandAuthorisationError : public std::runtime_error {
public:
    CommandAuthorisationError(const char* message)
        : std::runtime_error(message) {}
};

class RedirectError : public std::runtime_error {
public:
    RedirectError(const char* message)
        : std::runtime_error(message) {}
};

class UserAuthenticationRedirectError : public RedirectError {
public:
    UserAuthenticationRedirectError(const char* message)
        : RedirectError(message) {}
};

class AdminPanelRedirectError : public RedirectError {
public:
    AdminPanelRedirectError(const char* message)
        : RedirectError(message) {}
};

class AdminAuthenticationRedirectError : public RedirectError {
public:
    AdminAuthenticationRedirectError(const char* message)
        : RedirectError(message) {}
};

class UserInvalidCredentials : public std::runtime_error {
public:
    UserInvalidCredentials(const char* message)
        : std::runtime_error(message) {}
};


class UserNotInDatabaseException : public std::runtime_error {
public:
    UserNotInDatabaseException(const char* message)
        : std::runtime_error(message) {}
};