#pragma once
#include <iostream>
#include "BasePanel.h"
#include <sstream>
#include "../../Utility/Vector.hpp"
class AdminPanel : public BasePanel {

public:
	AdminPanel(BasePanel* prev, User* user);
	void printPrompth() const override;
	void runCommand(const MyString& command) override;
	void printHeaderPanelMessage() const override;
	void printCommandLocation() const override;
	BasePanel* clone() const override;
};