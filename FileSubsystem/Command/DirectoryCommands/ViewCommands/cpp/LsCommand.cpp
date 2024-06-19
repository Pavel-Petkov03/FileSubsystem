#include "../headers/LsCommand.h"
#include "../../ViewCommands/headers/CdCommand.h"
void LsCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	CdCommand cd;
	cd.runTaskOnLoggedDirectory(file, user, context, [](Directory*& currentDir, User* user, std::stringstream& context) {
		for (int i = 0; i < currentDir->children.getSize(); i++) {
			BaseFile* cur = currentDir->children[i].get();
			std::cout << cur->modificationDate << " " << cur->name << std::endl;
		}
		});
}