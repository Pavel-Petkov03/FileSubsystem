#pragma once
#include "BaseAdminCommand.hpp"
#include "../../Errors/Auth/CommandAuthorisationError.hpp"
#include <fstream>
class LoginCommand : public BaseAdminCommand {
private:
	void initUser(User*& user, std::stringstream& userContext);
	void login(std::ifstream& ifs, User*& user, std::stringstream& context);
public:
	void execute(User*& user, std::stringstream&  context) override;
	friend class RegisterCommand;
};


void LoginCommand::initUser(User*& user, std::stringstream& userContext)
{
	user = new User();
	while (true) {
		std::string groupName;
		userContext >> groupName;
		if (userContext.eof()) {
			return;
		}
		user->addToGroup(groupName);
	}
}

void LoginCommand::login(std::ifstream& ifs, User*& user, std::stringstream& context)
{
	if (user) {
		throw std::exception("User already logged in");
	}

	std::string username;
	std::string password;
	context >> username >> password;
	while (true) {
		char buffer[1024];
		ifs.getline(buffer, 1024);
		std::stringstream ss(buffer);
		std::string currentUsername;
		std::string currentPassword;
		ss >> currentUsername >> currentPassword;
		if (ifs.eof()) {
			throw UserNotInDatabaseException("There is no such user with this username");
		}
		if (currentUsername == username) {
			if (password == currentPassword) {
				initUser(user, ss);
				throw UserAuthenticationRedirectError("redirect");
			}
			else {
				throw UserInvalidCredentials("Invallid password");
			}
		}
	}
}

void LoginCommand::execute(User*& user, std::stringstream& context) {
	std::ifstream ifs("userDatabase.txt");
	try {
		login(ifs, user, context);
	}
	catch (UserNotInDatabaseException& error) {
		std::cout << error.what() << std::endl;
	}
	catch (UserInvalidCredentials& error) {
		std::cout << error.what() << std::endl;
	}
}