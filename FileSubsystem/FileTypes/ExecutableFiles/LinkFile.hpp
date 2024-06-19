#pragma once
#include "ExecutableFile.hpp"
#include "../../Utility/MyString.h"
class LinkFile : public ExecutableFile {
public:
	LinkFile(const MyString& name, BaseFile* parent);
	ExecutableFile* clone() const;
	void execute(User& user) override;
};

LinkFile::LinkFile(const MyString& name, BaseFile* parent) : ExecutableFile(name, parent) {

}

ExecutableFile* LinkFile::clone() const
{
	return new LinkFile(*this);
}

void LinkFile::execute(User& user)
{
	if (executed) {
		// throw circular import error;
	}
	executed = true;
	for (int i = 0; i < fileLines.getSize(); i++) {
		
	}
	executed = false;
}
