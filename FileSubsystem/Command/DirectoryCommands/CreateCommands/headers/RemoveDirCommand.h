#pragma once
#include "../headers/CreateCommand.h"
#include "../../../../FileTypes/Directory.h"
#include <sstream>
class RemoveDirCommand : public CreateCommand {
public:
	void runTask(Directory*& file, User*& user, std::stringstream& context) override;
};