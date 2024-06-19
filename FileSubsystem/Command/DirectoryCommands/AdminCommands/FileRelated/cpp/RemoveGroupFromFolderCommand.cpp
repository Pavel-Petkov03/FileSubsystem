#include "../headers/RemoveGroupFromFolderCommand.h"

void RemoveGroupFromFolderCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	MyString groupName;
	context >> groupName;
	file->removeGroup(*user, groupName);
}