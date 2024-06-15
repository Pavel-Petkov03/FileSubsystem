#pragma once
#include "BasePanel.hpp"
#include "../../Auth/User.hpp"
#include <sstream>
#include "../Command/AdminCommands/LoginCommand.hpp"
#include "../Command/AdminCommands/RegisterCommand.hpp"
class LoginAndRegistrationPanel : public BasePanel {
public:
	void printHeaderPanelMessage() const override;
	void runCommand(const std::string& str) override;
	void printPrompth() const override;
	LoginAndRegistrationPanel(BasePanel* prev, User* user);
};



void LoginAndRegistrationPanel::printPrompth() const
{

	std::cout << "Registration Commands" << std::endl;
	std::cout << "   register <username> <password>" << std::endl;
	std::cout << std::endl;
	std::cout << "Login Commands" << std::endl;
	std::cout << "   login <username> <password>" << std::endl;
}

LoginAndRegistrationPanel::LoginAndRegistrationPanel(BasePanel* prev, User* user) : BasePanel(prev, user)
{

}

void LoginAndRegistrationPanel::printHeaderPanelMessage() const
{
	std::cout << "Welcome to registration page" << std::endl;
}

void LoginAndRegistrationPanel::runCommand(const std::string& command)
{

	std::stringstream ss(command);
	std::string cmd;
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
