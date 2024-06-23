#pragma once
#include "ViewCommand.h"
#include "CdCommand.h"
class FindCommand : public ViewCommand {
private:
	static void find(Directory*& file, User*& user, const MyString& nameToFind);
	void runTask(Directory*& file, User*& user, std::stringstream& context) override;
};