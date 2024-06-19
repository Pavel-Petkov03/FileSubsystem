#pragma once
#include "CreateCommand.hpp"
#include "../../../Utility/MyString.h"
class MakeDirCommand : public CreateCommand {
public:
	void runTask(Directory*& file, User*& user, std::stringstream& context);
};

void MakeDirCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	MyString newDirName;
	context >> newDirName;
	if (file->getChildWithName(newDirName)) {
		std::cout << "File with name " << newDirName << " already in folder" << std::endl;
		return;
	}
	file->addFile(*user, new Directory(newDirName, file));
}