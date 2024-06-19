#include "../headers/CreateCommand.h"
bool CreateCommand::isUserAuthenticated(const User* user)
{
	if (BaseDirectoryCommand::isUserAuthenticated(user)) {
		return true;
	}
	return user->hasRole(RoleTypes::Editor);
}