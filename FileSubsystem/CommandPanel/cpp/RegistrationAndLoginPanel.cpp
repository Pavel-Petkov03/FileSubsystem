#include "../headers/RegistrationAndLoginPanel.h"
#include "../../Command/AdminCommands/headers/LoginCommand.h"
#include "../../Command/AdminCommands/headers/RegisterCommand.h"
void LoginAndRegistrationPanel::printPrompth() const
{

	std::cout << "Registration Commands" << std::endl;
	std::cout << "   register <username> <password>" << std::endl;
	std::cout << std::endl;
	std::cout << "Login Commands" << std::endl;
	std::cout << "   login <username> <password>" << std::endl;
}

void LoginAndRegistrationPanel::printCommandLocation() const
{
	std::cout << "registration# ";
}

LoginAndRegistrationPanel::LoginAndRegistrationPanel(BasePanel* prev, User* user) : BasePanel(prev, user)
{

}

void LoginAndRegistrationPanel::printHeaderPanelMessage() const
{
	std::cout << "Welcome to registration page" << std::endl;
}

void LoginAndRegistrationPanel::runCommand(const MyString& command)
{

	std::stringstream ss(command.c_str());
	MyString cmd;
	ss >> cmd;

	if (cmd == "login") {
		LoginCommand().execute((User*&)user, ss);
	}
	else if (cmd == "register") {
		RegisterCommand().execute((User*&)user, ss);
	}
	else {
		throw InvalidCommandInPanel("Invalid command");
	}
}