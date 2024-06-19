#pragma once
#include "LoginCommand.h"

class RegisterCommand : public BaseAdminCommand {
private:
	void _register(std::stringstream& stream);
public:
	void execute(User*& user, std::stringstream& context) override;
};