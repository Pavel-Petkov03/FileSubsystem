#pragma once
#include "../Auth/User.hpp"
#include "../FileTypes/BaseFile.hpp"
#include "../Errors/Auth/CommandAuthorisationError.hpp"
class BaseCommand {
protected:
	virtual void runTask(const BaseFile* file, User*& user) = 0;
public:
	virtual ~BaseCommand() = default;
	virtual void execute(const BaseFile* file, User*& user, std::stringstream& context) = 0;
};


 
