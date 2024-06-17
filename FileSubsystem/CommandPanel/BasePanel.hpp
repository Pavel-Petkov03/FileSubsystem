#pragma once
#include <iostream>
#include "../Errors/Panel/InvalidCommandInPanel.hpp"
#include "../Auth/User.hpp"
#include <string>
#include "../Utility/MyString.h"
class BasePanel {
protected:
	BasePanel* previousPanel;
	User* user;
public:
	virtual void printPrompth() const = 0;
	void run();
	virtual void printHeaderPanelMessage() const = 0;
	virtual void printCommandLocation() const = 0;
	BasePanel(BasePanel* prev, User* user);
	virtual ~BasePanel() = default;
	virtual void runCommand(const MyString& command) = 0;
	User* getUser() const;
};



void BasePanel::run() {
	printHeaderPanelMessage();
	MyString command;
	printCommandLocation();
	command.getLine(std::cin);
	while (true) {
		try {
			if (command == "--options") {
				printPrompth();
			}
			else if (command == "end") {
				break;
			}
			else {
				runCommand(command);
			}
		}
		catch (const InvalidCommandInPanel& error) {
			std::cout << error.what() << std::endl;
			std::cout << "Type --options to list all valid commands" << std::endl;
		}
		printCommandLocation();
		command.getLine(std::cin);
	}
}

BasePanel::BasePanel(BasePanel* prev, User* user) : previousPanel(prev), user(user)
{
}

User* BasePanel::getUser() const
{
	return user;
}

