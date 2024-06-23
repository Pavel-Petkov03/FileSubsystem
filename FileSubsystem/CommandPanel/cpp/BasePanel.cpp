#include "../headers/BasePanel.h"

void BasePanel::run() {
	printHeaderPanelMessage();
	MyString command;
	printCommandLocation();
	command.readConsoleLine();
	while (true) {
		try {
			if (command == "--options") {
				printPrompth();
			}
			else if (command == "end") {
				throw EscapePanelError("Escape panel"); 
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
		command.readConsoleLine();
	}
}

BasePanel::BasePanel(BasePanel* prev, User* user) : previousPanel(prev), user(user)
{
}

User* BasePanel::getUser() const
{
	return user;
}

BasePanel* BasePanel::getPreviousPanel()
{
	return previousPanel;
}
