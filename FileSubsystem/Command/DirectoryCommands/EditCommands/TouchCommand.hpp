#pragma once
#include "EditCommand.hpp"
#include "../../../FileTypes/ExecutableFiles/ExecutableFile.hpp"
#include "../../../Utility/MyString.h"
class TouchCommand : public EditCommand {
public:
	void runTask(Directory*& file, User*& user, std::stringstream& context);
};

void TouchCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	MyString filename;
	context << filename;
	BaseFile* currentFile = file->getChildWithName(filename);
	if (ExecutableFile* file  = dynamic_cast<ExecutableFile*>(currentFile)) {
		currentFile->modificationDate = currentFile->getCurrentDateTime();
		return;
	}

}