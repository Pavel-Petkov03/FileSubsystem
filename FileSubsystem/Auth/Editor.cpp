#include "Editor.h"
#include "../Command/EditCommand.h"
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
