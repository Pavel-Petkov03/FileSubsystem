#pragma once
#include <iostream>
#include "../Errors/Panel/InvalidCommandInPanel.hpp"
class BasePanel {
public:
	virtual void printPrompth() const = 0;
	void run() const;
	virtual void printHeaderPanelMessage() const = 0;
	virtual ~BasePanel() = default;
	BasePanel() = default;
	virtual void runCommand(const std::string& command) const = 0;
};



void BasePanel::run() const {
	printHeaderPanelMessage();
	std::string command;
	std::cin >> command;
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
		std::cin >> command;
	}
}