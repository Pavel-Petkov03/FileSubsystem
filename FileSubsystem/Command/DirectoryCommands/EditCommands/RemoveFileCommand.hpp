#pragma once
#include "EditCommand.hpp"
#include "../../../FileTypes/ExecutableFiles/ExecutableFile.hpp"
#include "../../../Utility/MyString.h"
class RemoveFileCommand : public EditCommand {
public:
	void runTask(Directory*& file, User*& user, std::stringstream& context);
};

void RemoveFileCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	MyString fileName;
	context >> fileName;
	BaseFile* currentFile = file->getChildWithName(fileName);
	if (currentFile) {
		if (ExecutableFile* d = dynamic_cast<ExecutableFile*>(currentFile)) {
			std::cout << "Can't remove file with command rmdir(try using rm)" << std::endl;
			return;
		}
		file->removeFile(*user, currentFile);
	}
}