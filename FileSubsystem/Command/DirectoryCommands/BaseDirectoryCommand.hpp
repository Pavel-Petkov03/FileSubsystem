#pragma once
#include "../../FileTypes/Directory.hpp"
#include "../../Errors/Auth/CommandAuthorisationError.hpp"
class BaseDirectoryCommand {
private:
	virtual void runTask(Directory*& file, User*& user, std::stringstream& context) = 0;
public:
	virtual bool isUserAuthenticated(const User* user) = 0;
	virtual void execute(Directory*& file, User*& user, std::stringstream& context);
};


bool BaseDirectoryCommand::isUserAuthenticated(const User* user) {
	if (user) {
		return user->hasRole(RoleTypes::Admin);
	}
}

void BaseDirectoryCommand::execute(Directory*& file, User*& user, std::stringstream& context)
{
	if (!isUserAuthenticated(user)) {
		throw CommandAuthorisationError("User has not the apropriate role to do this task");
	}
	if (!file->isAuthenticated(*user)) {
		throw CommandAuthorisationError("User doesn't have the required credentials for dir");
	}
	runTask(file, user, context);
}