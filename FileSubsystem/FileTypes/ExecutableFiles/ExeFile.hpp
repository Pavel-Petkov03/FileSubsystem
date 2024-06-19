#pragma once
#include "ExecutableFile.hpp"
#include "../../Utility/Vector.hpp"
#include "../../Utility/MyString.h"
#include "../../CommandPanel/DirectoryPanel.hpp"
class ExeFile : public ExecutableFile {
public:
	void execute(User& user);
	ExecutableFile* clone() const;
	ExeFile(const MyString& name, BaseFile* parent);
};

void ExeFile::execute(User& user) {
	if (executed) {
		// throw circular import error;
	}
	executed = true;
	//DirectoryPanel panel((Directory*)parent, &user);
	//for (int i = 0; i < fileLines.getSize(); i++) {
	//	panel.runCommand(fileLines[i]);
	//}
	executed = false;
}

ExecutableFile* ExeFile::clone() const
{
	return new ExeFile(*this);
}

ExeFile::ExeFile(const MyString& name, BaseFile* parent) : ExecutableFile(name, parent) {

}