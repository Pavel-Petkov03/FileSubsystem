#pragma once
#include "../headers/CreateCommand.h"
#include "../../../../Utility/MyString.h"
#include "../../../../FileTypes/Directory.h"
class MakeDirCommand : public CreateCommand {
public:
	void runTask(Directory*& file, User*& user, std::stringstream& context);
};
