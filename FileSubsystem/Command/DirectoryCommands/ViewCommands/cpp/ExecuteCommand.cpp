#include "../headers/ExecuteCommand.h"
#include "../../../../FileTypes/ExecutableFiles/headers/ExecutableFile.h"
void ExecuteCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	CdCommand cd;
	try {
		cd.runTaskOnLoggedFile(file, user, context, [](ExecutableFile*& file, User* user, std::stringstream& context) {
			file->execute(user);
			}, nullptr);
	}
	catch (CircularFileError& error) {
		std::cout << "Circle reference error: Contact Admin to fix the files related" << std::endl;
	}
}