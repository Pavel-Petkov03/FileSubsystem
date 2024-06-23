#pragma once
#include <iostream>
#include <chrono>
#include "CommandPanel/headers/RegistrationAndLoginPanel.h"
#include "CommandPanel//headers/AdminPanel.h"
#include "CommandPanel/headers/DirectoryPanel.h"
#include "Errors/Auth/CommandAuthorisationError.hpp"
#include <fstream>
class Runner {
private:
	BasePanel* currentPanel;
	Directory* currentDir;
	static void clearConsole();
	void chooseAdminPanel();
	void save();
	void load();
public:
	Runner();
	void run();
};