#pragma once
#include "ViewCommand.hpp"

class PwdCommand : public ViewCommand {
	void runTask(Directory*& file, User*& user, std::stringstream& context) override;
};

void PwdCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	std::cout << file->getPath() << std::endl;
}