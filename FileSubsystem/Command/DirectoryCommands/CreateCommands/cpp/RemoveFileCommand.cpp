#include "../headers/RemoveFileCommand.h"
#include "../../ViewCommands/headers/CdCommand.h"
void RemoveFileCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	CdCommand cd;
	cd.runTaskOnLoggedFile(file, user, context, [](ExecutableFile*& currentFile, User* user, std::stringstream& context) {
		Directory* parent = dynamic_cast<Directory*>(currentFile->parent);
		parent->removeFile(*user, currentFile);
		}, nullptr);
}