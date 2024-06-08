#include "Admin.h"

BaseRole* Admin::clone() const
{
	return new Admin(*this);
}

bool Admin::authorisedCommand(const BaseCommand*) const
{
	return true;
}
