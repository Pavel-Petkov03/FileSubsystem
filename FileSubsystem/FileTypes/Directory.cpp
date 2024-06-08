#include "Directory.h"

bool Directory::isAuthenticated(const User& user)
{
	if (user.isAdmin()) {
		return true;
	}
	return isInGroup(user);
}

bool Directory::isInGroup(const User& user)
{
	for (int i = 0; i < groups.getSize(); i++) {
		if (user.isInGroup(groups[i])){
			return true;
		}
	}
	return false;
}

void Directory::addFile(const User& user, const BaseFile* file)
{
	children.add(file);
}

BaseFile* Directory::clone() const
{
	return new Directory(*this);
}
