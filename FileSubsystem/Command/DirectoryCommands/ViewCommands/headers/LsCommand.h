#pragma once
#include "ViewCommand.h"
class LsCommand : public ViewCommand {
public:
	void runTask(Directory*& file, User*& user, std::stringstream& context) override;
};