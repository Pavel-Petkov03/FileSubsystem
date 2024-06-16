#pragma once
#include "ViewCommand.hpp"
#include <fstream>
#include <sstream>
class CdCommand : public ViewCommand {
private:
	void logToDirectory(Directory*& file, User*& user, std::stringstream& context);
public:
	void runTask(Directory*& file, User*& user, std::stringstream& context) override;
	friend class LsCommand;
	friend class FindCommand;
};

void CdCommand::logToDirectory(Directory*& file, User*& user, std::stringstream& context)
{
	std::string path;
	std::getline(context, path, '/');
	if (path.size()) {
		for (int i = 0; i < file->children.getSize(); i++) {
			if (file->children[i]->name == path) {
				if (Directory* d = dynamic_cast<Directory*>(file->children[i].get())) {
					logToDirectory(d, user, context);
					return;
				}
				else {
					std::cout << "File with name " << file->children[i]->name << " is not directory" << std::endl;
					return;
				}
			} 
		}
		std::cout << "No directory with such name:" << path << std::endl;
		return;
	}
	else {
		if (Directory* d = dynamic_cast<Directory*>(file)) {
			file = d;
		}
	}
}

void CdCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	
	try {
		logToDirectory(file, user, context);
	}
	catch (std::exception& err) {

	}
}