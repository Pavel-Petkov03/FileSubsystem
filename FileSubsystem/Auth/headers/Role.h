#pragma once
#include <ostream>

enum class RoleTypes {
	Admin=0,
	Editor=1,
	Viewer=2,
};
class BaseRole {
public:
	virtual BaseRole* clone() const = 0;
	virtual ~BaseRole() = default;
	virtual RoleTypes getType() const = 0;
	friend std::ostream& operator<<(std::ostream& ofs, const BaseRole&);
};

