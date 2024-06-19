#pragma once
#include <iostream>
#include "../../Errors/Panel/InvalidCommandInPanel.hpp"
#include "../../Auth/headers/User.h"
#include <string>
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