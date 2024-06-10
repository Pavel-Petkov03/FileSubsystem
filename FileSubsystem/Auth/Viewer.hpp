#pragma once
#include "Role.hpp"
#include "../Command/ViewCommand.hpp"
class Viewer : public BaseRole {
public:
	BaseRole* clone() const override;
	RoleTypes getType() const override;
};

BaseRole* Viewer::clone() const
{
	return new Viewer(*this);
}

RoleTypes Viewer::getType() const
{
	return RoleTypes::Viewer;
}
