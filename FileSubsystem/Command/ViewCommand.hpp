#pragma once
#include "BaseCommand.hpp"
class ViewCommand : public BaseCommand {
public:
	bool isUserAuthenticated(const User& user) override;
};

bool ViewCommand::isUserAuthenticated(const User& user) {
	return true;
}