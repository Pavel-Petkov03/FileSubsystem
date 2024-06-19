#pragma once
#include "CdCommand.h"
#include "ViewCommand.h"
class ExecuteCommand : public ViewCommand {
public:
	void runTask(Directory*& file, User*& user, std::stringstream& context);
};
