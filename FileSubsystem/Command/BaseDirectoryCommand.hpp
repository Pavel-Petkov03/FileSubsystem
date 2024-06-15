#pragma once
#include "../FileTypes/BaseFile.hpp"
#include "../Errors/Auth/CommandAuthorisationError.hpp"
class BaseDirectoryCommand {
private:
	virtual void runTask(const BaseFile* file, User*& user) = 0;
public:
	virtual bool isUserAuthenticated(const User* user) = 0;
	virtual void execute(const BaseFile* file, User*& user, std::stringstream& context) = 0;
};


bool BaseDirectoryCommand::isUserAuthenticated(const User* user) {
	if (user) {
		return user->hasRole(RoleTypes::Admin);
	}
}

void BaseDirectoryCommand::execute(const BaseFile* file, User*& user, std::stringstream& context)
{
	if (!isUserAuthenticated(user)) {
		throw CommandAuthorisationError("User has not the apropriate role to do this task");
	}
	runTask(file, user);
}