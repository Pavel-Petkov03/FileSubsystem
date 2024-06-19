#include "../headers/ExecuteCommand.h"
#include "../../../../FileTypes/ExecutableFiles/headers/ExecutableFile.h"
void ExecuteCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	CdCommand cd;
	cd.runTaskOnLoggedFile(file, user, context, [](ExecutableFile*& file, User* user, std::stringstream& context) {
		file->execute(user);
		}, nullptr);
}