#pragma once
#include "../Utility/PolymorphicPtr.hpp"
#include "Role.hpp"
#include "../Utility/Vector.hpp"
#include "Viewer.hpp"
#include "Editor.hpp"
class User {
private:
	Polymorphic_Ptr<BaseRole> role;
	Vector<std::string> groupsIn;
public: 
	bool hasRole(const BaseRole* role) const;
	bool isInGroup(std::string& groupName) const;
	bool isAdmin() const;
};


bool User::hasRole(const BaseRole* other) const
{
	if (dynamic_cast<const Admin*>(role.get()) && dynamic_cast<const Admin*>(other)) {
		return true;
	}
	if (dynamic_cast<const Editor*>(role.get()) && dynamic_cast<const Editor*>(other)) {
		return true;
	}
	if (dynamic_cast<const Viewer*>(role.get()) && dynamic_cast<const Viewer*>(other)) {
		return true;
	}
	return false;
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

bool User::isAdmin() const
{
	if (dynamic_cast<const Admin*>(role.get())) {
		return true;
	}
	return false;
}