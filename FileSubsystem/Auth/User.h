#pragma once
#include "../Utility/PolymorphicPtr.hpp"
#include "../Utility/PolymorphicContainer.hpp"
#include "Role.h"
class User {
private:
	Polymorphic_Ptr<BaseRole> role;
	Vector<std::string> groupsIn;
public: 
	bool hasRole(const BaseRole* role) const;
	bool isInGroup(std::string& groupName) const;
	bool isAdmin() const;
};