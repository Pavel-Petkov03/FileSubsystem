#include "../headers/FindCommand.h"

void FindCommand::find(Directory*& file, User*& user, const MyString& nameToFind) {

	for (int i = 0; i < file->children.getSize(); i++) {
		if (file->children[i]->name.isSubstr(nameToFind)) {
			std::cout << file->children[i]->name << std::endl;
		}
		if (Directory* d = dynamic_cast<Directory*>(file->children[i].get())) {
			if (d->isAuthenticated(*user)) {
				find(d, user, nameToFind);
			}
		}
	}
}

void FindCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	CdCommand cdCommand;
	cdCommand.runTaskOnLoggedDirectory(file, user, context, [](Directory*& currentDir, User* user, std::stringstream& context) {
		find(currentDir, user, MyString(context.str().c_str()));
	});
}