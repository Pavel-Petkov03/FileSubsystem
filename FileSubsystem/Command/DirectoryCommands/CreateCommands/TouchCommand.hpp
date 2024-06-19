#pragma once
#include "CreateCommand.hpp"
#include "../../../FileTypes/ExecutableFiles/ExecutableFile.hpp"
#include "../../../Utility/MyString.h"
#include "../../../FileTypes/ExecutableFiles/ExeFile.hpp"
#include "../../../FileTypes/ExecutableFiles/TxtFile.hpp"
#include "../../../FileTypes/ExecutableFiles//LinkFile.hpp"
class TouchCommand : public CreateCommand {
private:
	static ExecutableFile* fileFactory(Directory*& file, const MyString& str);
	static void addFile(Directory*& currentExecutable, User* user, std::stringstream& context);
	static void modifyFile(ExecutableFile*& currentExecutable, User* user, std::stringstream& context);
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

void TouchCommand::addFile(Directory*& currentExecutable, User* user, std::stringstream& context)
{
	MyString filename;
	context >> filename;
	currentExecutable->addFile(*user, fileFactory(currentExecutable, filename));
}

void TouchCommand::modifyFile(ExecutableFile*& currentExecutable, User* user, std::stringstream& context)
{
	currentExecutable->setModificationDate();
}

void TouchCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	CdCommand cd;
	cd.runTaskOnLoggedFile(file, user, context, modifyFile, addFile);
}