//#pragma once
//#include "ViewCommand.hpp"
//#include "CdCommand.hpp"
//class FindCommand : public ViewCommand {
//private:
//	void find(Directory*& file, User*& user, std::string nameToFind);
//	void runTask(Directory*& file, User*& user, std::stringstream& context) override;
//	bool isSubstring(const MyString& text, std::string substr);
//};
//
//
//
//void FindCommand::find(Directory*& file, User*& user, std::string nameToFind){
//
//	for (int i = 0; i < file->children.getSize(); i++) {
//		try {
//			if (isSubstring(file->children[i]->name, nameToFind)) {
//				std::cout << file->children[i]->name << std::endl;
//			}
//			if (Directory* d = dynamic_cast<Directory*>(file->children[i].get())) {
//				if (d->isAuthenticated(*user)) {
//					find(d, user, nameToFind);
//				}
//			}
//		}
//		catch (...) {
//
//		}
//	}
//}
//
//void FindCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
//	CdCommand cdCommand;
//	try {
//		cdCommand.logToDirectory(file, user, context);
//		find(file, user, context.str());
//	}
//	catch (...) {
//		todo handle
//	}
//}
//
//bool FindCommand::isSubstring(const MyString&, std::string substr)
//{
//	return true;
//}
