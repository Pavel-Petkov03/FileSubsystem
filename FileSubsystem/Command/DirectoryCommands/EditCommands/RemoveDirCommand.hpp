#pragma once
#include "CreateCommand.hpp"
class RemoveDirCommand : public CreateCommand {
public:
	void runTask(Directory*& file, User*& user, std::stringstream& context);
};

void RemoveDirCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	MyString fileName;
	context >> fileName;
	BaseFile* currentFile = file->getChildWithName(fileName);
	if (currentFile) {
		if (Directory* d = dynamic_cast<Directory*>(currentFile)) {
			file->removeFile(*user, currentFile);
			return;
		}
		std::cout << "Can't remove directory with command rm(try using rmdir)" << std::endl;
		return;
	}
}