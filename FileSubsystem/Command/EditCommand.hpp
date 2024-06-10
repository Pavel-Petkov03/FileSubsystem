#pragma once
#include "BaseCommand.hpp"
#include "EditCommand.hpp"
#include "../Auth/Admin.hpp"
#include "../Auth/Editor.hpp"
class EditCommand : public BaseCommand {
public:
	virtual bool isUserAuthenticated(const User& user);
};

bool EditCommand::isUserAuthenticated(const User& user)
{
	if (BaseCommand::isUserAuthenticated(user)) {
		return true;
	}
	return user.hasRole(RoleTypes::Editor);
}
