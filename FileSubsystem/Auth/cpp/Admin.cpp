#include "../headers/Admin.h"
BaseRole* Admin::clone() const
{
	return new Admin(*this);
}

RoleTypes Admin::getType() const
{
	return RoleTypes::Admin;
}