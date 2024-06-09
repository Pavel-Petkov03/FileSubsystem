#pragma once
#include "BaseFile.hpp"
#include "../Auth/Role.hpp"
#include "../Utility/Vector.hpp"
#include "../Utility/PolymorphicPtr.hpp"
#include <ostream>
class Directory : public BaseFile {
private:
	Vector<Polymorphic_Ptr<BaseRole>> rolesRequired;
	Vector<Polymorphic_Ptr<BaseFile>> children;
	Vector<std::string> groups;
	bool isInGroup(const User& user);
public:
	void addFile(const User& user, BaseFile* file);
	BaseFile* clone() const override;
	bool isAuthenticated(const User& user);
	Directory(const std::string& name, const User& creator, BaseFile* parent);
	friend std::ostream& operator<<(std::ostream& ofs, const Directory& other);
};


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
		if (user.isInGroup(groups[i])) {
			return true;
		}
	}
	return false;
}

Directory::Directory(const std::string& name, const User& creator, BaseFile* parent) : BaseFile(name, creator, parent)
{

}



void Directory::addFile(const User& user, BaseFile* file)
{
	children.pushBack(file);
}

BaseFile* Directory::clone() const
{
	return new Directory(*this);
}

std::ostream& operator<<(std::ostream& ofs, const Directory& directory)
{
	operator<<(ofs, static_cast<const BaseFile&>(directory));
	return ofs;
}