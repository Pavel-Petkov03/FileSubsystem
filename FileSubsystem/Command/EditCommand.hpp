#pragma once
#include "../Auth/Admin.hpp"
#include "../Auth/Editor.hpp"
#include "BaseDirectoryCommand.hpp"
class EditCommand : public BaseDirectoryCommand {
public:
	virtual bool isUserAuthenticated(const User* user);
};

bool EditCommand::isUserAuthenticated(const User* user)
{
	if (BaseDirectoryCommand::isUserAuthenticated(user)) {
		return true;
	}
	return user->hasRole(RoleTypes::Editor);
}
