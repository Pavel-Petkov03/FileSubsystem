#pragma once

#include "../../BaseFile.h"
#include "../../../Auth/headers/User.h"
#include "../../../Errors/FileErrors.hpp"
class ExecutableFile : public BaseFile {
protected:
	Vector<MyString> fileLines;
	bool executed = false;

public:
	ExecutableFile(const MyString& name, BaseFile* parent);
	virtual void execute(User* user) = 0;
	virtual ~ExecutableFile() = default;

	friend class EchoCommand;
	friend class RemoveFileCommand;
};