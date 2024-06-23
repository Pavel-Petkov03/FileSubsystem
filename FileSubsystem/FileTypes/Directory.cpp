#include "Directory.h"
bool Directory::isAuthenticated(const User& user)
{
	if (!parent || user.hasRole(RoleTypes::Admin)) {
		return true;
	}
	return isInGroup(user);
}

bool Directory::isInGroup(const User& user)
{
	if (groups.getSize() == 0) {
		return true;
	}
	for (int i = 0; i < groups.getSize(); i++) {
		if (user.isInGroup(groups[i])) {
			return true;
		}
	}
	return false;
}

Directory::Directory(const MyString& name, BaseFile* parent) : BaseFile(name, parent)
{

}

Directory::Directory(const MyString& name, BaseFile* parent, const Vector<Polymorphic_Ptr<BaseFile, fileFactory>>& children, const Vector<MyString>& groups) :
	BaseFile(name, parent), children(children), groups(groups)
{

}



BaseFile* Directory::getChildWithName(const MyString& str)
{

	for (int i = 0; i < children.getSize(); i++) {
		if (children[i]->name == str) {
			return children[i].get();
		}
	}
	return nullptr;
}

void Directory::buildTree()
{
	buildTreeRecurse(*this);
}

void Directory::addFile(const User& user, BaseFile* file)
{
	if (isAuthenticated(user)) {
		children.pushBack(file);
		return;
	}
}

void Directory::addGroup(const User& user, const MyString& groupName)
{
	if (groups.hasElement(groupName)) {
		std::cout << "Group name already in folder" << std::endl;
		return;
	}
	if (!isAuthenticated(user)) {
		std::cout << "User not Authenticated to add file " << std::endl;
		return;
	}
	groups.pushBack(groupName);
}

void Directory::removeGroup(const User& user, const MyString& groupName)
{
	for (int i = 0; i < groups.getSize(); i++) {
		if (groups[i] == groupName) {
			groups.removeAtIndex(i);
			std::cout << "Successfully removed group with name " << groupName << std::endl;
			return;
		}
	}
	std::cout << "No group with such name" << std::endl;
}

void Directory::removeFile(const User& user, BaseFile* file)
{
	if (!isAuthenticated(user)) {
		std::cout << "Group name already in folder" << std::endl;
		return;
	}
	for (int i = 0; i < children.getSize(); i++) {
		if (file == children[i].get()) {
			children.removeAtIndex(i);
		}
	}
}

void Directory::buildTreeRecurse(Directory& dir)
{
	for (int i = 0; i < dir.children.getSize(); i++) {
		dir.children[i]->parent = &dir;
		if (Directory* current = dynamic_cast<Directory*>(dir. children[i].get())) {
			buildTreeRecurse(*current);
		}
	}
}

void Directory::serialise(std::ostream& ofs) const
{
	if (parent) {
		ofs << (int)getType() << '\n';
	}
	operator<<(ofs, static_cast<const BaseFile&>(*this));
	ofs << children;
	ofs << groups;
}

void Directory::deserialise(std::istream& ifs)
{
	operator>>(ifs, static_cast<BaseFile&>(*this));
	ifs >> children;
	ifs >> groups;
}

FileTypes Directory::getType() const
{
	return FileTypes::DirectoryType;
}

BaseFile* Directory::clone() const
{
	return new Directory(*this);
}


std::istream& operator>>(std::istream& ifs, Directory& other)
{
	operator>>(ifs, static_cast<BaseFile&>(other));
	ifs >> other.children;
	ifs >> other.groups;
	return ifs;
}