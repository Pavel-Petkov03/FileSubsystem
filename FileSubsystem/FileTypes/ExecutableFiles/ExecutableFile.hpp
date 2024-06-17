#pragma once
#include "../BaseFile.hpp"

class ExecutableFile : public BaseFile {
public:
	ExecutableFile(const MyString& name, BaseFile* parent);
	virtual void execute() const = 0;
	virtual ~ExecutableFile() = default;
};

ExecutableFile::ExecutableFile(const MyString& name, BaseFile* parent) : BaseFile(name, parent) {

}