#pragma once
#include "BaseAdminCommand.h"
#include "../../Errors/Auth/CommandAuthorisationError.hpp"
#include <fstream>
class LoginCommand : public BaseAdminCommand {
private:
	void initUser(User*& user, std::stringstream& userContext);
	void login(std::ifstream& ifs, User*& user, std::stringstream& context);
	static RoleTypes getRoleType(int n);
public:
	void execute(User*& user, std::stringstream& context) override;
	friend class RegisterCommand;
};
