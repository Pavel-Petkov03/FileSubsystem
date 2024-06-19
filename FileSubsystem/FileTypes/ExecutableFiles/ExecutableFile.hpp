#pragma once
#include "../BaseFile.hpp"

class ExecutableFile : public BaseFile {
protected:
	Vector<MyString> fileLines;
	bool executed = false;

public:
	ExecutableFile(const MyString& name, BaseFile* parent);
	virtual void execute(User* user) = 0;
	virtual ~ExecutableFile() = default;

	friend class EchoCommand;
};

ExecutableFile::ExecutableFile(const MyString& name, BaseFile* parent) : BaseFile(name, parent) {

}