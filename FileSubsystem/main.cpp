#include <iostream>
#include <chrono>
#include "CommandPanel/headers/RegistrationAndLoginPanel.h"
#include "CommandPanel//headers/AdminPanel.h"
#include "CommandPanel/headers/DirectoryPanel.h"
#include "Errors/Auth/CommandAuthorisationError.hpp"
class Runner {
private:
	Polymorphic_Ptr<BasePanel> currentPanel;

	void chooseAdminPanel();
public:
	Runner();
	void run();
};
void Runner::chooseAdminPanel()
{
	std::cout << "Welcome to admin panel" << std::endl;
	std::cout << "Type 1 to enter directory" << std::endl;
	std::cout << "Type 2 to enter admin command panel" << std::endl;

	int n;
	while (true) {
		std::cin >> n;
		if (n == 1) {
			currentPanel = new DirectoryPanel(currentPanel.get(), currentPanel->getUser());
		}
		else if (n == 2) {
			currentPanel = new AdminPanel(currentPanel.get(), currentPanel->getUser());
		}
		std::cout << "Invalid command" << std::endl;
		std::cin >> n;
	}
	
}
Runner::Runner()
{
	currentPanel = new LoginAndRegistrationPanel(nullptr, nullptr);
}

void Runner::run()
{
	while (true) {
		try {
			currentPanel->run();
		}
		catch (UserAuthenticationRedirectError& err) {
			User* user = currentPanel->getUser();
			if (user->hasRole(RoleTypes::Admin)) {
				chooseAdminPanel();
				continue;
			}
			currentPanel = new DirectoryPanel(currentPanel.get(), user);
		}
	}
}

int main() {
	Runner runner;
	runner.run();
}