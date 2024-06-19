#include "../headers/User.h"

bool User::hasRole(const RoleTypes& type) const
{
	return type == role.get()->getType();
}

bool User::isInGroup(const MyString& groupName) const
{
	for (int i = 0; i < groupsIn.getSize(); i++) {
		if (groupName == groupsIn[i]) {
			return true;
		}
	}
	return false;
}

void User::addToGroup(const MyString& groupName)
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
