#pragma once
#include "ViewCommand.h"

class PwdCommand : public ViewCommand {
	void runTask(Directory*& file, User*& user, std::stringstream& context) override;
};