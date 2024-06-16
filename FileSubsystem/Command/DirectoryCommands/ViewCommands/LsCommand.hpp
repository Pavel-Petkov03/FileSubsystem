#pragma once
#include "CdCommand.hpp"
class LsCommand : public ViewCommand {
public:
	void runTask(Directory*& file, User*& user, std::stringstream& context) override;
}; 



void LsCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	try {
		CdCommand cd;
		Directory* currentDir = file;
		cd.logToDirectory(currentDir, user, context);
		for (int i = 0; i < file->children.getSize(); i++) {
			BaseFile* cur = file->children[i].get();
			std::cout << cur->modificationDate << " " << cur->name << std::endl;
		}
	}
	catch (...) {
		//todo handle
	}
}
