#include "Runner.h"
void Runner::clearConsole()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();
}
void Runner::chooseAdminPanel()
{
	std::cout << "Welcome to admin panel" << std::endl;
	std::cout << "Type 1 to enter directory" << std::endl;
	std::cout << "Type 2 to enter admin command panel" << std::endl;

	int n;
	while (true) {
		std::cin >> n;
		if (n == 1) {
			currentPanel = new DirectoryPanel(currentPanel, currentDir, currentPanel->getUser());
			return;
		}
		else if (n == 2) {
			currentPanel = new AdminPanel(currentPanel, currentPanel->getUser());
			return;
		}
		std::cout << "Invalid command" << std::endl;
		std::cin >> n;
	}
}
void Runner::save()
{
	std::ofstream ofs("directory.txt");
	currentDir->serialise(ofs);
}
void Runner::load()
{
	std::ifstream ifs("directory.txt");

	if (!ifs.is_open()) {
		MyString rootName = "root";
		currentDir = new Directory(rootName, nullptr);
		return;
	}
	currentDir = new Directory();
	ifs >> *currentDir;
	currentDir->buildTree();
}
Runner::Runner()
{
	currentPanel = new LoginAndRegistrationPanel(nullptr, nullptr);
	load();
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
				clearConsole();
				continue;
			}
			currentPanel = new DirectoryPanel(currentPanel, currentDir, user);
		}
		catch (const EscapePanelError& err) {
			BasePanel* current = currentPanel->getPreviousPanel();
			delete currentPanel;
			if (!current) {
				save();
				return;
			}
			currentPanel = current;
		}
	}
}