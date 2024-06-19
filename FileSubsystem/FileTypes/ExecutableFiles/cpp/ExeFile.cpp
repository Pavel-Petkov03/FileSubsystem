#include "../headers/ExeFile.h"

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