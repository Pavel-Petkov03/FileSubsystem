#pragma once
#include "BaseDirectoryCommand.hpp"
class ViewCommand : public BaseDirectoryCommand {
public:
	bool isUserAuthenticated(const User* user) override;
};

bool ViewCommand::isUserAuthenticated(const User* user) {
	return true;
}