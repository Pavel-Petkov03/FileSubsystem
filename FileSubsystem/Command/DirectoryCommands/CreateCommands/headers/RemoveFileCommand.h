#pragma once
#include "CreateCommand.h"
#include "../../../../FileTypes/Directory.h"
#include "../../../../FileTypes/ExecutableFiles/headers/ExecutableFile.h"
class RemoveFileCommand : public CreateCommand {
public:
	void runTask(Directory*& file, User*& user, std::stringstream& context);
};