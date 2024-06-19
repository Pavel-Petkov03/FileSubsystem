#include "../headers/PwdCommand.h"
void PwdCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	std::cout << file->getPath() << std::endl;
}