#pragma once
#include <ostream>

enum class RoleTypes {
	Admin,
	Editor,
	Viewer,
};
class BaseRole {
public:
	virtual BaseRole* clone() const = 0;
	virtual ~BaseRole() = default;
	virtual RoleTypes getType() const = 0;
	friend std::ostream& operator<<(std::ostream& ofs, const BaseRole&);
};


std::ostream& operator<<(std::ostream& ofs, const BaseRole& role)
{
	ofs << (int)role.getType() << std::endl;
	return ofs;
}