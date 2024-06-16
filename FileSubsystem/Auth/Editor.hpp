#pragma once
#include "Role.hpp"
class Editor: public BaseRole {
public:
	BaseRole* clone() const override;
	RoleTypes getType() const override;
};

BaseRole* Editor::clone() const
{
	return new Editor(*this);
}

RoleTypes Editor::getType() const
{
	return RoleTypes::Editor;
}