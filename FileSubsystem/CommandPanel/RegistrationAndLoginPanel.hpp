#pragma once
#include "BasePanel.hpp"
#include "../../Auth/User.hpp"
#include <sstream>
class LoginAndRegistrationPanel : public BasePanel {
private:
	User* user;
public:
	LoginAndRegistrationPanel() = default;
	void printHeaderPanelMessage() const override;
	void runCommand(const std::string& str) const override;
	void printPrompth() const override;
};



void LoginAndRegistrationPanel::printPrompth() const
{

	std::cout << "Registration Commands" << std::endl;
	std::cout << "   register <username> <password>" << std::endl;
	std::cout << std::endl;
	std::cout << "Login Commands" << std::endl;
	std::cout << "   login <username> <password>" << std::endl;
}

void LoginAndRegistrationPanel::printHeaderPanelMessage() const
{
	std::cout << "Welcome to registration page" << std::endl;
}

void LoginAndRegistrationPanel::runCommand(const std::string& command) const
{
	std::stringstream ss(command);
	std::string cmd;
	std::string username;
	std::string password;
	ss >> cmd >> username >> password;

	if (cmd == "login") {

	}
	else if (cmd == "register") {

	}
	else {
		throw InvalidCommandInPanel("Invalid command");
	}
}
