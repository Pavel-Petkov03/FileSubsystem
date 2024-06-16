#pragma once
#include "EditCommand.hpp"
class RemoveDirCommand : public EditCommand {
public:
	void runTask(Directory*& file, User*& user, std::stringstream& context);
};

void RemoveDirCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	std::string fileName;
	context >> fileName;
	BaseFile* currentFile = file->getChildWithName(fileName);
	if (currentFile) {
		if (Directory* d = dynamic_cast<Directory*>(currentFile)) {
			std::cout << "Cant remove directory with command rm(try using rmdir)" << std::endl;
			return;
		}
		file->removeFile(*user, currentFile);
	}
}