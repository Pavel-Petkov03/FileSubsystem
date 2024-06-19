#pragma once
#include "CdCommand.hpp"
class LsCommand : public ViewCommand {
public:
	void runTask(Directory*& file, User*& user, std::stringstream& context) override;
}; 



void LsCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	CdCommand cd;
	cd.runTaskOnLoggedDirectory(file, user, context, [](Directory*& currentDir, User* user, std::stringstream& context) {
		for (int i = 0; i < currentDir->children.getSize(); i++) {
			BaseFile* cur = currentDir->children[i].get();
			std::cout << cur->modificationDate << " " << cur->name << std::endl;
		}
	});

}
