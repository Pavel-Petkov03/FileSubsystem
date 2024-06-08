#include "BaseFile.h"
#include "../Auth/Role.h"
#include "../Utility/PolymorphicContainer.hpp"
class Directory : public BaseFile {
private:
	Polymorphic_Container<BaseRole> rolesRequired;
	Polymorphic_Container<BaseFile> children;
	Vector<std::string> groups;
	
public:
	void addFile(const User& user, const BaseFile* file);
	BaseFile* clone() const override; 
	bool isAuthenticated(const User& user);
	bool isInGroup(const User& user);
};