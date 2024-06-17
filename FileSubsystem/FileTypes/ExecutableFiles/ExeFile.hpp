#pragma once
#include "ExecutableFile.hpp"
#include "../../Utility/Vector.hpp"
#include "../../Utility/MyString.h"
class ExeFile : public ExecutableFile {
private:
	Vector<MyString> commandLines;
public:
	void execute() const;
	ExecutableFile* clone() const;
	ExeFile(const MyString& name, BaseFile* parent);
};

void ExeFile::execute() const {

}

ExecutableFile* ExeFile::clone() const
{
	return new ExeFile(*this);
}

ExeFile::ExeFile(const MyString& name, BaseFile* parent) : ExecutableFile(name, parent) {

}