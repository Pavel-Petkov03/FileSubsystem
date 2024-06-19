#pragma once
#include "ViewCommand.hpp"
#include "CdCommand.hpp"
class ExecuteCommand : public ViewCommand {
public:
	void runTask(Directory*& file, User*& user, std::stringstream& context);
};


void ExecuteCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	CdCommand cd;
	cd.runTaskOnLoggedFile(file, user, context, [](ExecutableFile*& file, User* user, std::stringstream& context) {
		file->execute(user);
	}, nullptr);
}