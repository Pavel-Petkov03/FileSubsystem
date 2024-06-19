#pragma once
#pragma once
#include "ViewCommand.h"
#include "../../../../FileTypes/ExecutableFiles/headers/ExecutableFile.h"
class EchoCommand : public ViewCommand {
private:
	static void changeFile(ExecutableFile* file, const MyString& text);
	static void modifyFile(ExecutableFile* file, const MyString& text);
public:
	void runTask(Directory*& file, User*& user, std::stringstream& context) override;
};