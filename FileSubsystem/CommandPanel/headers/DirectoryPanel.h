#pragma once
#include "BasePanel.h"
#include "../../FileTypes/Directory.h"


class DirectoryPanel : public BasePanel {
private:
	void printCreateCommands() const;
	void printViewCommands() const;
	void printAdminCommands() const;
	void runCreateCommands(std::stringstream& context);
	void runViewComamnds(std::stringstream& context);
	void runAdminCommands(std::stringstream& context);
	void printCommandLocation() const override;
	Directory* currentDir;
public:
	DirectoryPanel(BasePanel* prev, User* user);
	DirectoryPanel(Directory* currentDir, User* user);
	void printHeaderPanelMessage() const override;
	void runCommand(const MyString& command) override;
	void printPrompth() const override;
};