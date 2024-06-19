#pragma once
#include "../../Auth/headers/User.h"
#include "../../FileTypes/Directory.h"
#include "../../Errors/Auth/CommandAuthorisationError.hpp"
#include <sstream>
class BaseDirectoryCommand {
private:
	virtual void runTask(Directory*& file, User*& user, std::stringstream& context) = 0;
public:
	virtual bool isUserAuthenticated(const User* user) = 0;
	virtual void execute(Directory*& file, User*& user, std::stringstream& context);
};