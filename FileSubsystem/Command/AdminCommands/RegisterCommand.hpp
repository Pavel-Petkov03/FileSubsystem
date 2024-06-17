#pragma once
#include "BaseAdminCommand.hpp"
#include "LoginCommand.hpp"

class RegisterCommand : public BaseAdminCommand {
private: 
	void _register(std::stringstream& stream);
public:
	void execute(User*& user, std::stringstream& context) override;
};



void RegisterCommand::_register(std::stringstream& stream)
{
	MyString dummyCommand;
	stream >> dummyCommand;
	std::ofstream ofs("userDatabase.txt", std::ios::app);
	if (!ofs.is_open()) {
		return;
	}
	MyString username;
	MyString password;
	stream >> username >> password;
	ofs << username << " " << password << " " << "2" << std::endl;
	ofs.close();
	throw UserAuthenticationRedirectError("User created");
}

void RegisterCommand::execute(User*& user, std::stringstream& context) {

	std::ifstream ifs("userDatabase.txt");
	if (!ifs.is_open()) {
		std::cout << ":<";
		return;
	}
	try {
		LoginCommand loginCommand;
		loginCommand.login(ifs, user, context);
	}
	catch (UserNotInDatabaseException& error) {
		context.seekg(0, std::ios::beg);
		user = new User(RoleTypes::Viewer);
		_register(context);
	}
	catch (UserInvalidCredentials& error) {
		std::cout << "There is user with this name" << std::endl;
	}
}