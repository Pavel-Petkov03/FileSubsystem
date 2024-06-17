#pragma once
#include "BaseAdminCommand.hpp"
#include "../../Errors/Auth/CommandAuthorisationError.hpp"
#include <fstream>
class LoginCommand : public BaseAdminCommand {
private:
	void initUser(User*& user, std::stringstream& userContext);
	void login(std::ifstream& ifs, User*& user, std::stringstream& context);
	static RoleTypes getRoleType(int n);
public:
	void execute(User*& user, std::stringstream&  context) override;
	friend class RegisterCommand;
};


void LoginCommand::initUser(User*& user, std::stringstream& userContext)
{
	int roleType;
	userContext >> roleType;

	user = new User(getRoleType(roleType));
	while (true) {
		MyString groupName;
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

	MyString username;
	MyString password;
	context >> username >> password;
	if (!username || !password) {
		std::cout << "username or password cannot be empty" << std::endl;
		return;
	}
	while (true) {
		char buffer[1024];
		ifs.getline(buffer, 1024);
		std::stringstream ss(buffer);
		MyString currentUsername;
		MyString currentPassword;
		ss >> currentUsername >> currentPassword;
		if (ifs.eof()) {
			throw UserNotInDatabaseException("There is no such user with this username");
		}
		if (currentUsername == username && username) {
			if (password == currentPassword && password) {
				initUser(user, ss);
				throw UserAuthenticationRedirectError("redirect");
			}
			else {
				throw UserInvalidCredentials("Invallid password");
			}
		}
	}
}

RoleTypes LoginCommand::getRoleType(int n)
{
	switch (n)
	{
	case 0:
		return RoleTypes::Admin;
	case 1:
		return RoleTypes::Editor;
	case 2:
		return RoleTypes::Viewer;
	default:
		break;
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