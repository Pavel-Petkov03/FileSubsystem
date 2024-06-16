#pragma once
#include "../Utility/PolymorphicPtr.hpp"
#include "../Utility/Vector.hpp"
#include "../Auth/Role.hpp"
#include "../Auth/Viewer.hpp"
#include "../Auth/Editor.hpp"
#include "../Auth/Admin.hpp"
class User {
private:
	Polymorphic_Ptr<BaseRole> role;
	Vector<std::string> groupsIn;
public: 
	bool hasRole(const RoleTypes& type) const;
	bool isInGroup(std::string& groupName) const;
	void addToGroup(std::string& groupName);
	User(const RoleTypes& role);
};


bool User::hasRole(const RoleTypes& type) const
{
	return type == role.get()->getType();
}

bool User::isInGroup(std::string& groupName) const
{
	for (int i = 0; i < groupsIn.getSize(); i++) {
		if (groupName == groupsIn[i]) {
			return true;
		}
	}
	return false;
}

void User::addToGroup(std::string& groupName)
{
	groupsIn.pushBack(groupName);
}

User::User(const RoleTypes& role)
{
	switch (role) {
	case RoleTypes::Admin:
		this->role = new Admin();
		break;
	case RoleTypes::Editor:
		this->role = new Editor();
		break;
	case RoleTypes::Viewer:
		this->role = new Viewer();
		break;
	}
}
