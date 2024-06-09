#pragma once
#include "Role.hpp"
#include "../Command/ViewCommand.hpp"
class Viewer : public BaseRole {
public:
	BaseRole* clone() const override;
	bool authorisedCommand(const BaseCommand*) const override;
	RoleTypes getType() const override;
};

BaseRole* Viewer::clone() const
{
	return new Viewer(*this);
}

bool Viewer::authorisedCommand(const BaseCommand* command) const
{
	if (dynamic_cast<const ViewCommand*>(command)) {
		return true;
	}
	return false;
}

RoleTypes Viewer::getType() const
{
	return RoleTypes::Viewer;
}
