#pragma once
#include "../../../BaseDirectoryCommand.h"
class AddGroupToFolderCommand : public BaseDirectoryCommand {
public:
	void runTask(Directory*& file, User*& user, std::stringstream& context);
};