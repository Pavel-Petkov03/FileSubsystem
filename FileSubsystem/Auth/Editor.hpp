#pragma once
#include "Role.hpp"
#include "../Command/EditCommand.hpp"
class Editor: public BaseRole {
public:
	BaseRole* clone() const override;
	bool authorisedCommand(const BaseCommand* command) const override;
	RoleTypes getType() const override;
};

BaseRole* Editor::clone() const
{
	return new Editor(*this);
}

bool Editor::authorisedCommand(const BaseCommand* command) const
{
	if (dynamic_cast<const EditCommand*>(command)) {
		return true;
	}
	return false;
}

RoleTypes Editor::getType() const
{
	return RoleTypes::Editor;
}