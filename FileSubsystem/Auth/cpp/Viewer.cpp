#include "../headers/Viewer.h"
BaseRole* Viewer::clone() const
{
	return new Viewer(*this);
}

RoleTypes Viewer::getType() const
{
	return RoleTypes::Viewer;
}
