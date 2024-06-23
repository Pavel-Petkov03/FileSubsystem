#pragma once
#include "BasePanel.h"
#include "../../Auth/headers/User.h"
#include <sstream>

class LoginAndRegistrationPanel : public BasePanel {
public:
	void printHeaderPanelMessage() const override;
	void runCommand(const MyString& str) override;
	void printPrompth() const override;
	void printCommandLocation() const override;
	LoginAndRegistrationPanel(BasePanel* prev, User* user);

	BasePanel* clone() const override;
};
