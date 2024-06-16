#pragma once
#include "../../Auth/User.hpp"
#include <sstream>
#include<string>
class BaseAdminCommand {
public:
	virtual  void execute(User*& user, std::stringstream& context) = 0;
	virtual ~BaseAdminCommand() = default;
}; 