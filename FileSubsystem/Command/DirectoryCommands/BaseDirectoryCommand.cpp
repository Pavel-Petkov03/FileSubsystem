#include "BaseDirectoryCommand.h"

bool BaseDirectoryCommand::isUserAuthenticated(const User* user) {
	if (user) {
		return user->hasRole(RoleTypes::Admin);
	}
	return false;
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