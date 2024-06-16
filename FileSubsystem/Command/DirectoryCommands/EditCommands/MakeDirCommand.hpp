#pragma once
#include "EditCommand.hpp"
class MakeDirCommand : public EditCommand {
public:
	void runTask(Directory*& file, User*& user, std::stringstream& context);
};

void MakeDirCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	std::string newDirName;
	context >> newDirName;
	if (file->getChildWithName(newDirName)) {
		std::cout << "File with name " << newDirName << " already in folder" << std::endl;
		return;
	}
	file->addFile(*user, new Directory(newDirName, file));
}