#include "../headers/AdminPanel.h"


AdminPanel::AdminPanel(BasePanel* prev, User* user) : BasePanel(prev, user)
{

}

void AdminPanel::printPrompth() const
{
	std::cout << "User related commands:" << std::endl;
	std::cout << "   change_user_role <username>" << std::endl;
	std::cout << "   delete_user <username>" << std::endl;
	std::cout << "   add_user_to_group <groupName>" << std::endl;
	std::cout << "   remove_user_from_group <groupName>" << std::endl;
	std::cout << std::endl;
}

void AdminPanel::runCommand(const MyString& command)
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
	else {
		throw InvalidCommandInPanel("Invalid Admin command");
	}
}

void AdminPanel::printHeaderPanelMessage() const
{
	std::cout << "Welcome to Admin Panel" << std::endl;
}

void AdminPanel::printCommandLocation() const
{
	std::cout << "admin# ";
}