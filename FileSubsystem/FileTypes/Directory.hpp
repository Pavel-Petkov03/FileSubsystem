#pragma once
#include "BaseFile.hpp"
#include "../Auth/Role.hpp"
#include "../Utility/Vector.hpp"
#include "../Utility/PolymorphicPtr.hpp"
#include <ostream>
class Directory : public BaseFile {
private:
	Vector<Polymorphic_Ptr<BaseFile>> children;
	Vector<std::string> groups;
	bool isInGroup(const User& user);
public:
	void addFile(const User& user, BaseFile* file);
	void addGroup(const User& user, std::string& groupName);
	BaseFile* clone() const override;
	bool isAuthenticated(const User& user);
	Directory() = default;
	Directory(const std::string& name, BaseFile* parent);
	Directory(const std::string& name, BaseFile* parent, const Vector<Polymorphic_Ptr<BaseFile>>& children, const Vector<std::string>& groups);
	friend std::ostream& operator<<(std::ostream& ofs, const Directory& other);
	friend std::istream& operator>>(std::istream& ifs, Directory& other);

	friend class CdCommand;
};


bool Directory::isAuthenticated(const User& user)
{
	if (!parent || user.hasRole(RoleTypes::Admin)) {
		return true;
	}
	return isInGroup(user);
}

bool Directory::isInGroup(const User& user)
{
	for (int i = 0; i < groups.getSize(); i++) {
		if (user.isInGroup(groups[i])) {
			return true;
		}
	}
	return false;
}

Directory::Directory(const std::string& name ,BaseFile* parent) : BaseFile(name, parent)
{

}

Directory::Directory(const std::string& name ,BaseFile* parent, const Vector<Polymorphic_Ptr<BaseFile>>& children, const Vector<std::string>& groups) :
	BaseFile(name, parent), children(children), groups(groups)
{

}



void Directory::addFile(const User& user, BaseFile* file)
{
	if (isAuthenticated(user)) {
		children.pushBack(file);
		return;
	}
	// todo throw
}

void Directory::addGroup( const User& user, std::string& groupName)
{
	if (groups.hasElement(groupName)) {
		// todo throw error
	}
	if (!isAuthenticated(user)) {
		//todo throw error
	}
	groups.pushBack(groupName);
}

BaseFile* Directory::clone() const
{
	return new Directory(*this);
}

std::ostream& operator<<(std::ostream& ofs, const Directory& directory)
{
	operator<<(ofs, static_cast<const BaseFile&>(directory));
	ofs << directory.children;
	ofs << directory.groups;
	return ofs;
}

std::istream& operator>>(std::istream& ifs, Directory& other)
{
	return ifs;
}
