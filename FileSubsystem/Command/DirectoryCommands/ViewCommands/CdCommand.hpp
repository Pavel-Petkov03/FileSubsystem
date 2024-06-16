#pragma once
#include "ViewCommand.hpp"

class CdCommand : public ViewCommand {
public:
	void runTask(Directory*& file, User*& user, std::stringstream& context) override;

};

void CdCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	std::string path;
	context >> path;
	if (path.size()) {
		for (int i = 0; i < file->children.getSize(); i++) {
			if (file->children[i]->name == path){
				if (Directory* d = dynamic_cast<Directory*>(file->children[i].get())) {
					file = d;
					return;
				}
				else {
					std::cout << "Cannot cd a file with name:" << file->children[i]->name << std::endl;
					return;
				}
			}
		}
		std::cout << "No file with such name:" << path << std::endl;
		return;
	}
}