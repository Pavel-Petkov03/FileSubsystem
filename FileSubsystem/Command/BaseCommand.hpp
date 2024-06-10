#pragma once
#include "../Auth/User.hpp"
#include "../FileTypes/BaseFile.hpp"
#include "../Errors/Auth/CommandAuthorisationError.hpp"
class BaseCommand {
private:
	virtual void runTask(const BaseFile* file, const User& user) = 0;
public:
	virtual ~BaseCommand() = default;
	virtual bool isUserAuthenticated(const User& user);
	virtual void execute(const BaseFile* file, const User& user) final;
};


bool BaseCommand::isUserAuthenticated(const User& user) {
	return user.hasRole(RoleTypes::Admin);
}

void BaseCommand::execute(const BaseFile* file, const User& user)
{
	if (!isUserAuthenticated(user)) {
		throw CommandAuthorisationError("User has not the apropriate role to do this task");
	}
	runTask(file, user);
}
 