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
	void runCreateCommands(std::stringstream& context);
	void runViewComamnds(std::stringstream& context);
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
	std::cout << "   rmdir <dirName>" << std::endl;
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

void DirectoryPanel::runCreateCommands(std::stringstream& context)
{

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
	try {
		
		runViewComamnds(ss);
	}
	catch (InvalidCommandInPanel& error) {
		
		if (user->hasRole(RoleTypes::Admin) || user->hasRole(RoleTypes::Editor)) {
			ss.seekg(0, std::ios::beg);
			runCreateCommands(ss);
			return;
		}
		throw InvalidCommandInPanel("Invalid View command");
	}
}

void DirectoryPanel::printPrompth() const
{
	if (user->hasRole(RoleTypes::Admin) || user->hasRole(RoleTypes::Editor)) {
		printCreateCommands();
	}
	printViewCommands();
}

