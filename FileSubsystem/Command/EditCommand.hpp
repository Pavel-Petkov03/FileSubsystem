#pragma once
#include "BaseCommand.hpp"
#include "EditCommand.hpp"
#include "../Auth/Admin.hpp"
#include "../Auth/Editor.hpp"
class EditCommand : public BaseCommand {
public:
	EditCommand();
	void execute() override;
};
EditCommand::EditCommand()
{

}

void EditCommand::execute()
{

}
