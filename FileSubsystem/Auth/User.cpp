#include "User.h"
#include "Admin.h"
#include "Viewer.h"
#include "Editor.h"
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
