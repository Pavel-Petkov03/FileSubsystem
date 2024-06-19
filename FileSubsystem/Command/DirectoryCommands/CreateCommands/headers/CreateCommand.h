#pragma once
#include "../../../../Auth/headers/User.h"
#include "../../BaseDirectoryCommand.h"
class CreateCommand : public BaseDirectoryCommand {
public:
	virtual bool isUserAuthenticated(const User* user);
};