#pragma once

#include "BasePanel.hpp"
class DirectoryPanel : public BasePanel {
private:
	void printCreateCommands() const;
	void printViewCommands() const;

public:
	DirectoryPanel(BasePanel* prev, User* user);
	void printHeaderPanelMessage() const override;
	void runCommand(const std::string& command) override;
	void printPrompth() const override;
};

void DirectoryPanel::printCreateCommands() const
{

}

void DirectoryPanel::printViewCommands() const
{

}

DirectoryPanel::DirectoryPanel(BasePanel* prev, User* user): BasePanel(prev, user) {

}

void DirectoryPanel::printHeaderPanelMessage() const
{
	std::cout << "Welcome to Directory" << std::endl;
}

void DirectoryPanel::runCommand(const std::string& command) {

}

void DirectoryPanel::printPrompth() const
{
	if (user->hasRole(RoleTypes::Admin) || user->hasRole(RoleTypes::Editor)) {
		printCreateCommands();
		printViewCommands();
	}
	else {
		printViewCommands();
	}
}

