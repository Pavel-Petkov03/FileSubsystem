#pragma once
#include "CreateCommand.hpp"
#include "../../../FileTypes/ExecutableFiles/ExecutableFile.hpp"
#include "../../../Utility/MyString.h"
#include "../../../FileTypes/ExecutableFiles/ExeFile.hpp"
#include "../../../FileTypes/ExecutableFiles/TxtFile.hpp"
#include "../../../FileTypes/ExecutableFiles//LinkFile.hpp"
class TouchCommand : public CreateCommand {
private:
	ExecutableFile* fileFactory(Directory*& file, const MyString& str);
public:
	void runTask(Directory*& file, User*& user, std::stringstream& context);
};

ExecutableFile* TouchCommand::fileFactory(Directory*& file, const MyString& str)
{
	MyString extension = str.substr(str.getLength() - 4, str.getLength());
	if (extension == ".exe") {
		return new ExeFile(str, file);
	}
	else if (extension == ".lnk") {
		return new LinkFile(str, file);
	}
	else if(extension == ".txt") {
		return new TxtFile(str, file);
	}
	else {
		return new TxtFile(str, file);
	}
}

void TouchCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	MyString filename;
	context >> filename;
	BaseFile* currentFile = file->getChildWithName(filename);
	if (currentFile) {
		currentFile->modificationDate = currentFile->getCurrentDateTime();
		std::cout << "Change modification date for " << currentFile->name << std::endl;
		return;
	}
	file->addFile((const User&)user, fileFactory(file, filename));
}