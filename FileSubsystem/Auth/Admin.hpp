#pragma once
#include "Role.hpp"


class Admin : public BaseRole {
public:
	BaseRole* clone() const override;
	RoleTypes getType() const override;
	friend std::ostream& operator<<(std::ostream&, const Admin& other);
};

BaseRole* Admin::clone() const
{
	return new Admin(*this);
}


RoleTypes Admin::getType() const
{
	return RoleTypes::Admin;
}

std::ostream& operator<<(std::ostream& ofs, const Admin& other)
{
	ofs << "ffewfew";
	return ofs;
}