#include "../headers/Editor.h"
BaseRole* Editor::clone() const
{
	return new Editor(*this);
}

RoleTypes Editor::getType() const
{
	return RoleTypes::Editor;
}