#pragma once
#pragma once
#include "../../Utility/PolymorphicPtr.hpp"
#include "../../Utility/Vector.hpp"
#include "Role.h"
#include "Viewer.h"
#include "Editor.h"
#include "Admin.h"
#include "../../Utility/MyString.h"
#include "roleFactory.h"
class User {
private:
	Polymorphic_Ptr<BaseRole, roleFactory> role;
	Vector<MyString> groupsIn;
public:
	bool hasRole(const RoleTypes& type) const;
	bool isInGroup(const MyString& groupName) const;
	void addToGroup(const MyString& groupName);
	User(const RoleTypes& role);
};