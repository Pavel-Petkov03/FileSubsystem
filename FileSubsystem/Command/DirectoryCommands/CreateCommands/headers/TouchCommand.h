#pragma once
#pragma once
#include "CreateCommand.h"
#include "../../../../FileTypes/Directory.h"
#include "../../../../FileTypes/ExecutableFiles/headers/ExecutableFile.h"
class TouchCommand : public CreateCommand {
private:
	static ExecutableFile* fileFactory(Directory*& file, const MyString& str);
	static void addFile(Directory*& currentExecutable, User* user, std::stringstream& context);
	static void modifyFile(ExecutableFile*& currentExecutable, User* user, std::stringstream& context);
public:
	void runTask(Directory*& file, User*& user, std::stringstream& context);
};
