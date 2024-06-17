#pragma once
#include "../../../Auth/Editor.hpp"
#include "../../../Auth/User.hpp"
#include "../BaseDirectoryCommand.hpp"
class CreateCommand : public BaseDirectoryCommand {
public:
	virtual bool isUserAuthenticated(const User* user);
};

bool CreateCommand::isUserAuthenticated(const User* user)
{
	if (BaseDirectoryCommand::isUserAuthenticated(user)) {
		return true;
	}
	return user->hasRole(RoleTypes::Editor);
}
