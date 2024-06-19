#include "../headers/DirectoryPanel.h"

#include "../../Command/DirectoryCommands/CreateCommands/headers/MakeDirCommand.h"
#include "../../Command/DirectoryCommands/CreateCommands/headers/RemoveDirCommand.h"
#include "../../Command/DirectoryCommands/CreateCommands/headers/RemoveFileCommand.h"
#include "../../Command/DirectoryCommands/CreateCommands/headers/TouchCommand.h"

#include "../../Command/DirectoryCommands/ViewCommands/headers/CdCommand.h"
#include "../../Command/DirectoryCommands/ViewCommands/headers/LsCommand.h"
#include "../../Command/DirectoryCommands/ViewCommands/headers/PwdCommand.h"
#include "../../Command/DirectoryCommands/ViewCommands/headers/ExecuteCommand.h"
#include "../../Command/DirectoryCommands/ViewCommands/headers/EchoCommand.h"

#include <fstream>

void DirectoryPanel::printCreateCommands() const
{
	std::cout << "Create/Delete commands:" << std::endl;
	std::cout << "   mkdir <dirName>" << std::endl;
	std::cout << "   touch <fileName>" << std::endl;
	std::cout << "   rm <fileName>" << std::endl;
	std::cout << "   rmdir <dirName>" << std::endl;
}

void DirectoryPanel::printViewCommands() const
{
	std::cout << "View/Modify commands:" << std::endl;
	std::cout << "   cd <path>" << std::endl;
	std::cout << "   ls" << std::endl;
	std::cout << "   ls <path>" << std::endl;
	std::cout << "   pwd" << std::endl;
	std::cout << "   find <startPath> <findStr> " << std::endl;
	std::cout << "   echo <text>" << std::endl;
	std::cout << "   echo <text> > <path>" << std::endl;
	std::cout << "   echo <text> >> <path>" << std::endl;
	std::cout << "   exec <path>" << std::endl;
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
	MyString cmd;
	context >> cmd;
	if (cmd == "mkdir") {
		MakeDirCommand().execute(currentDir, user, context);
	}
	else if (cmd == "rmdir") {
		RemoveDirCommand().execute(currentDir, user, context);
	}
	else if (cmd == "rm") {
		RemoveFileCommand().execute(currentDir, user, context);
	}
	else if (cmd == "touch") {
		TouchCommand().execute(currentDir, user, context);
	}
	else {
		context.seekg(std::ios::beg);
		runViewComamnds(context);
	}
}

void DirectoryPanel::runViewComamnds(std::stringstream& context)
{
	MyString cmd;
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
	else if (cmd == "exec") {
		ExecuteCommand().execute(currentDir, user, context);
	}
	else if (cmd == "echo") {
		EchoCommand().execute(currentDir, user, context);
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

void DirectoryPanel::printCommandLocation() const
{
	std::cout << currentDir->getPath() << "# ";
}


DirectoryPanel::DirectoryPanel(BasePanel* prev, User* user) : BasePanel(prev, user) {
	std::ifstream ifs("directory.txt");

	if (!ifs.is_open()) {
		MyString rootName = "root";
		currentDir = new Directory(rootName, nullptr);
		return;
	}
	currentDir = new Directory();
	ifs >> *currentDir;
}

DirectoryPanel::DirectoryPanel(Directory* currentDir, User* user) : BasePanel(nullptr, user)
{
	this->currentDir = currentDir;
}

void DirectoryPanel::printHeaderPanelMessage() const
{
	std::cout << "Welcome to Directory" << std::endl;
}

void DirectoryPanel::runCommand(const MyString& command) {

	std::stringstream ss(command.c_str());
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