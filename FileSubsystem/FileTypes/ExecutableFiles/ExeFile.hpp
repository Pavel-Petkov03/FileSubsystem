#pragma once
#include "ExecutableFile.hpp"
#include "../../Utility/Vector.hpp"
#include "../../Utility/MyString.h"


class ExeFile : public ExecutableFile {
private:
public:
	void execute(User* user);
	ExecutableFile* clone() const;
	ExeFile(const MyString& name, BaseFile* parent);
};

void ExeFile::execute(User* user) {
	if (executed) {
		// throw circular import error;
	}
	executed = true;
	executed = false;
}

ExecutableFile* ExeFile::clone() const
{
	return new ExeFile(*this);
}

ExeFile::ExeFile(const MyString& name, BaseFile* parent) : ExecutableFile(name, parent) {

}