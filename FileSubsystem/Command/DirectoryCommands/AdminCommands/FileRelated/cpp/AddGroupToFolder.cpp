#include "../headers/AddGroupToFolderCommand.h"

void AddGroupToFolderCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	MyString groupName;
	context >> groupName;
	file->addGroup(*user, groupName);
}