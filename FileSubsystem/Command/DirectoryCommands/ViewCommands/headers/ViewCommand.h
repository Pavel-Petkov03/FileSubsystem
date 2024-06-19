#pragma once
#include "../../BaseDirectoryCommand.h"
class ViewCommand : public BaseDirectoryCommand {
public:
	bool isUserAuthenticated(const User* user) override;
};