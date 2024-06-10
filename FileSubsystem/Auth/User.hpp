#pragma once
#include "../Utility/PolymorphicPtr.hpp"
#include "../Utility/Vector.hpp"
#include "../Auth/Role.hpp"
class User {
private:
	Polymorphic_Ptr<BaseRole> role;
	Vector<std::string> groupsIn;
public: 
	bool hasRole(const RoleTypes& type) const;
	bool isInGroup(std::string& groupName) const;
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
