#pragma once
#include <sstream>
#include "BasePanel.hpp"
#include "../FileTypes/Directory.hpp"
#include "../Command/DirectoryCommands/ViewCommands/PwdCommand.hpp"
#include "../Command/DirectoryCommands/ViewCommands/CdCommand.hpp"
#include "../Command/DirectoryCommands/ViewCommands/LsCommand.hpp"
class DirectoryPanel : public BasePanel {
private:
	void printCreateCommands() const;
	void printViewCommands() const;
	void printAdminCommands() const;
	void runCreateCommands(std::stringstream& context);
	void runViewComamnds(std::stringstream& context);
	void runAdminCommands(std::stringstream& context);
	Directory* currentDir;
public:
	DirectoryPanel(BasePanel* prev, User* user);
	void printHeaderPanelMessage() const override;
	void runCommand(const std::string& command) override;
	void printPrompth() const override;
};

void DirectoryPanel::printCreateCommands() const
{
	std::cout << "Create commands:" << std::endl;
	std::cout << "   mkdir <dirName>" << std::endl;
	std::cout << "   touch <fileName>" << std::endl;
	std::cout << "   rm <fileName>" << std::endl;
	std::cout << "   rmdir <dirName>" << std::endl;
	std::cout << "   exec <fileName>" << std::endl;
	std::cout << "   echo <text>" << std::endl;
	std::cout << "   echo <text> > <fileName>" << std::endl;
	std::cout << "   echo <text> >> <fileName>" << std::endl;
}

void DirectoryPanel::printViewCommands() const
{
	std::cout << "View commands:" << std::endl;
	std::cout << "   cd <path>" << std::endl;
	std::cout << "   ls" << std::endl;
	std::cout << "   ls <path>" << std::endl;
	std::cout << "   pwd" << std::endl;
	std::cout << "   find <startPath> <findStr> " << std::endl;
}

void DirectoryPanel::printAdminCommands() const
{
	std::cout << "User related commands:" << std::endl;
	std::cout << "   add_user_to_group <groupName>" << std::endl;
	std::cout << "   remove_user_from_group <groupName>" << std::endl;
	std::cout << std::endl;
	std::cout << "File related commands" << std::endl;
	std::cout << "   add_group_to_folder <folderName> <groupName>" << std::endl;
	std::cout << "   remove_group_from_folder <folderName> <groupName>" << std::endl;
}

void DirectoryPanel::runCreateCommands(std::stringstream& context)
{
	if (true) {

	}
	else {
		context.seekg(std::ios::beg);
		runViewComamnds(context);
	}
}

void DirectoryPanel::runViewComamnds(std::stringstream& context)
{
	std::string cmd;
	context >> cmd;
	if (cmd == "cd") {
		CdCommand().execute(currentDir, user, context);
	}
	else if (cmd == "ls") {
		LsCommand().execute(currentDir, user, context);
	}
	else if (cmd == "pwd") {
		PwdCommand().execute(currentDir, user, context);
	}
	else if (cmd == "find") {

	}
	else {
		throw InvalidCommandInPanel("Invalid command");
	}
}

void DirectoryPanel::runAdminCommands(std::stringstream& context)
{
	if (true) {

	}
	else {
		context.seekg(std::ios::beg);
		runCreateCommands(context);
	}
}


DirectoryPanel::DirectoryPanel(BasePanel* prev, User* user): BasePanel(prev, user) {
	std::ifstream ifs("directory.txt");

	if (!ifs.is_open()) {
		std::string rootName = "root";
		currentDir = new Directory(rootName, nullptr);
	}
	currentDir = new Directory();
	ifs >> *currentDir;
}

void DirectoryPanel::printHeaderPanelMessage() const
{
	std::cout << "Welcome to Directory" << std::endl;
}

void DirectoryPanel::runCommand(const std::string& command) {
		
	std::stringstream ss(command);
	if (user->hasRole(RoleTypes::Admin)) {
		runAdminCommands(ss);
	}
	else if (user->hasRole(RoleTypes::Editor)) {
		runCreateCommands(ss);
	}
	else {
		runViewComamnds(ss);
	}
}

void DirectoryPanel::printPrompth() const
{
	if (user->hasRole(RoleTypes::Admin)) {
		printAdminCommands();
	}
	if (user->hasRole(RoleTypes::Admin) || user->hasRole(RoleTypes::Editor)) {
		printCreateCommands();
	}
	printViewCommands();
}

