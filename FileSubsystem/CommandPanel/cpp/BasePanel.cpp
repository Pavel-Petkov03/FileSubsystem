#include "../headers/BasePanel.h"

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