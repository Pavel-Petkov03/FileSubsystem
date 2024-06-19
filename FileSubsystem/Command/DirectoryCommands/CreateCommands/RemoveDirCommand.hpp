#pragma once
#include "CreateCommand.hpp"
#include "../ViewCommands/CdCommand.hpp"
class RemoveDirCommand : public CreateCommand {
public:
	void runTask(Directory*& file, User*& user, std::stringstream& context);
};

void RemoveDirCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	CdCommand cd;
	Directory* copy = file;
	cd.runTaskOnLoggedDirectory(copy, user, context, [](Directory*& currentFile, User* user, std::stringstream& context) {
		Directory* parent = dynamic_cast<Directory*>(currentFile->parent);
		parent->removeFile(*user, currentFile);
	});
}