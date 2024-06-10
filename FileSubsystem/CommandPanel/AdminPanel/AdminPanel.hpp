#pragma once
#include <iostream>
#include "../BasePanel.hpp"
#include "../../Errors/Panel/InvalidCommandInAdmin.hpp"
#include <sstream>
class AdminPanel : public BasePanel {
public:
	void printPrompth() const override;
	void run() const override;
	void runCommand(const std::string& command, bool running) const;
};



void AdminPanel::printPrompth() const
{
	std::cout << "User related commands:" << std::endl;
	std::cout << "   change_user_role <username>";
	std::cout << "   delete_user <username>" << std::endl;
	std::cout << "   add_user_to_group <groupName>" << std::endl;
	std::cout << "   remove_user_from_group <groupName>" << std::endl;
	std::cout << std::endl;
	std::cout << "File related commands" << std::endl;
	std::cout << "   add_group_to_folder <folderName> <groupName>" << std::endl;
	std::cout << "   remove_group_from_folder <folderName> <groupName>" << std::endl;
}

void AdminPanel::run() const  {
	std::cout << "Welcome to admin panel" << std::endl;
	bool running = true;
	std::string command;
	while (running) {
		try {
			runCommand(command, running);
		}
		catch (const InvalidCommandInAdmin& error) {
			std::cout << error.what() << std::endl;
			std::cout << "Type --options to list all valid commands" << std::endl;
		}
	}
}

void AdminPanel::runCommand(const std::string& command, bool running) const
{
	if (command == "end") {
		running = false;
		return;
	}
	if (command == "--options") {
		printPrompth();
	}
	std::stringstream ss(command);
	std::string cmd;
	ss >> cmd;
	if (cmd == "change_user_role") {

	}
	else if (cmd == "delete_user") {

	}
	else if (cmd == "add_user_to_group") {

	}
	else if (cmd == "remove_user_from_group") {

	}
	else if (cmd == "add_group_to_folder") {

	}
	else if (cmd == "remove_group_from_folder") {

	}
	else {
		throw InvalidCommandInAdmin("Invalid Admin command");
	}
}
