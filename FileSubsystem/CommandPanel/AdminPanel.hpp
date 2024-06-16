#pragma once
#include <iostream>
#include "BasePanel.hpp"
#include <sstream>
#include "../../Utility/Vector.hpp"
#include "../Errors/Panel/InvalidCommandInPanel.hpp"
class AdminPanel : public BasePanel {

public:
	AdminPanel(BasePanel* prev, User* user);
	void printPrompth() const override;
	void runCommand(const std::string& command) override;
	void printHeaderPanelMessage() const override;
};


AdminPanel::AdminPanel(BasePanel* prev, User* user) : BasePanel(prev , user)
{

}

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

void AdminPanel::runCommand(const std::string& command)
{
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
		throw InvalidCommandInPanel("Invalid Admin command");
	}
}

void AdminPanel::printHeaderPanelMessage() const
{
	std::cout << "Welcome to Admin Panel" << std::endl;
}
