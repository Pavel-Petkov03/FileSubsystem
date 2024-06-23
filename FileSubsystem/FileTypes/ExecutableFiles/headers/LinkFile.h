#pragma once
#include "ExecutableFile.h"
#include "../../Utility/MyString.h"
#include "../../../Command/DirectoryCommands/ViewCommands/headers/CdCommand.h"
class LinkFile : public ExecutableFile {
private:
	CdCommand cd;
public:
	LinkFile(const MyString& name, BaseFile* parent);
	LinkFile() = default;
	ExecutableFile* clone() const;
	FileTypes getType() const override;
	void execute(User* user) override;
};