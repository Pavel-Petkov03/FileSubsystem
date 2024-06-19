#pragma once
#include "../../../BaseDirectoryCommand.h"
class RemoveGroupFromFolderCommand : public BaseDirectoryCommand {
public:
	void runTask(Directory*& file, User*& user, std::stringstream& context);
};