#include "../headers/RemoveDirCommand.h"
#include "../../ViewCommands/headers/CdCommand.h"
void RemoveDirCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	CdCommand cd;
	Directory* copy = file;
	cd.runTaskOnLoggedDirectory(copy, user, context, [](Directory*& currentFile, User* user, std::stringstream& context) {
		Directory* parent = dynamic_cast<Directory*>(currentFile->parent);
		parent->removeFile(*user, currentFile);
		});
}