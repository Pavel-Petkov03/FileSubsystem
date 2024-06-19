#pragma once
#include "../../../Auth/headers/User.h"
#include <sstream>
#include<string>
class BaseAdminCommand {
public:
	virtual  void execute(User*& user, std::stringstream& context) = 0;
	virtual ~BaseAdminCommand() = default;
};