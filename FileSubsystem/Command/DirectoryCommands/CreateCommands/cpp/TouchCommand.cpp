#include "../headers/TouchCommand.h"
#include "../../../../FileTypes/ExecutableFiles/headers/ExeFile.h"
#include "../../../../FileTypes/ExecutableFiles/headers/LinkFile.h"
#include "../../../../FileTypes/ExecutableFiles/headers/TxtFile.h"
ExecutableFile* TouchCommand::fileFactory(Directory*& file, const MyString& str)
{
	MyString extension = str.substr(str.getLength() - 4, str.getLength());
	if (extension == ".exe") {
		return new ExeFile(str, file);
	}
	else if (extension == ".lnk") {
		return new LinkFile(str, file);
	}
	else if (extension == ".txt") {
		return new TxtFile(str, file);
	}
	else {
		return new TxtFile(str + MyString(".txt"), file);
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