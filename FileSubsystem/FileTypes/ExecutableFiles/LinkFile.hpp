#pragma once
#include "ExecutableFile.hpp"
#include "../../Utility/MyString.h"
class LinkFile : public ExecutableFile {
private:
	MyString link;
public:
	LinkFile(const MyString& name, BaseFile* parent);
	ExecutableFile* clone() const;
	void execute() const override;
};

LinkFile::LinkFile(const MyString& name, BaseFile* parent) : ExecutableFile(name, parent) {

}

ExecutableFile* LinkFile::clone() const
{
	return new LinkFile(*this);
}

void LinkFile::execute() const
{

}
