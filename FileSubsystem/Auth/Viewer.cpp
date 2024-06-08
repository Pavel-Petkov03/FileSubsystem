#include "Viewer.h"
#include "../Command/ViewCommand.h"
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
