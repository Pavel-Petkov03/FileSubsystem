#pragma once
#include "BaseFile.h"
#include "../Utility/Vector.hpp"
#include "../Utility/PolymorphicPtr.hpp"
#include "../Utility/MyString.h"
#include "../Auth/headers/User.h"
#include <ostream>
class Directory : public BaseFile {
private:
	Vector<Polymorphic_Ptr<BaseFile>> children;
	Vector<MyString> groups;
	bool isInGroup(const User& user);
	void addFile(const User& user, BaseFile* file);
	void addGroup(const User& user, const MyString& groupName);
	void removeGroup(const User& user, const MyString& groupName);
	void removeFile(const User& user, BaseFile* file);
public:
	BaseFile* getChildWithName(const MyString& str);

	BaseFile* clone() const override;
	bool isAuthenticated(const User& user);
	Directory() = default;
	Directory(const MyString& name, BaseFile* parent);
	Directory(const MyString& name, BaseFile* parent, const Vector<Polymorphic_Ptr<BaseFile>>& children, const Vector<MyString>& groups);

	friend std::ostream& operator<<(std::ostream& ofs, const Directory& other);
	friend std::istream& operator>>(std::istream& ifs, Directory& other);

	friend class CdCommand;
	friend class LsCommand;
	friend class FindCommand;

	friend class RemoveFileCommand;
	friend class RemoveDirCommand;
	friend class TouchCommand;
	friend class MakeDirCommand;

	friend class AddGroupToFolderCommand;
	friend class RemoveGroupFromFolderCommand;
};